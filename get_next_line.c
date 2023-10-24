/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:48:23 by anadal-g          #+#    #+#             */
/*   Updated: 2023/10/24 11:33:50 by anadal-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*free_line(char **line, void *tmp)
{
	if (tmp)
		free (tmp);
	if (*line)
		free(*line);
	*line = NULL;
	tmp = NULL;
	return (NULL);
}

char	*ft_get_line(char *save)
{
	int		i;
	char	*line;

	i = 0;
	if (!save || !save[i])
		return (NULL);
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (free_line(&save, NULL));
	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_save(char *buf)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	if (!buf)
		return (NULL);
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (ft_strlen(buf) - i + 1));
	if (!s)
		return (free_line(&buf, NULL));
	if (buf[i] == '\n')
		i += 1;
	c = 0;
	while (buf[i] != '\0')
	{
		s[c] = buf[i];
		i++;
		c++;
	}
	s[c] = '\0';
	free(buf);
	return (s);
}

char	*ft_read_and_save(int fd, char *save)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (free_line(&save, NULL));
	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(save, '\n'))
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free_line(&save, buff));
		if (buff[0] == '\0')
		{
			free(buff);
			//buff = NULL;
			return (save);
		}
		buff[read_bytes] = '\0';
		save = ft_strjoin(save, buff);
		if (!save)
			return(free_line(&save, buff));
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	//printf("\t## Buffer: [%s]\n", save);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free_line(&save, NULL));
	if (!save || !ft_strchr(save, '\n'))
		save = ft_read_and_save(fd, save);
	if (!save)
		return (free_line(&save, NULL));
	line = ft_get_line(save);
	if (!line)
		return (free_line(&save, line));
	save = ft_save(save);
	if (!save[0])
	{
		free(save);
		save = NULL;
	}
	return (line);
	/*if (line)
	{
		save = ft_save(save);
	}
	else
	{
		free(save);
		save = NULL;
	}
	return (line);*/
}

/*void leaks()
{
	system("leaks -q a.out");
}
int	main(void)
{
	int fd;
	char *str;

	fd = open("files/42_no_nl", O_RDONLY);

	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);

	close(fd);
	//leaks();	
	return(0);
}*/