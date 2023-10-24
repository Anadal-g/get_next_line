/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:48:45 by anadal-g          #+#    #+#             */
/*   Updated: 2023/10/24 11:24:39 by anadal-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*(src + i))
	{
		i++;
	}
	if (!size)
		return (i);
	while (--size && *src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (i);
}

char	*ft_strdup(char *str)
{
	size_t	len;
	//int index;
	char	*copy;

	//index = 0;
	len = ft_strlen(str) + 1;
	copy = (char *)malloc(len);
	if (copy == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(copy, str, len +1);
	/*while (str[index])
	{
		copy[index] = str[index];
		index++;
	}*/
	return (copy);
}

size_t	ft_strlen(char *str)
{
	size_t	c;

	c = 0;
	if (!str)
		return (0);
	while (str[c] != '\0')
		c++;
	return (c);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!s1)
		return (ft_strdup(s2));
	//if (!s2)
	//	return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	c = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[c] != '\0')
	{
		str[i] = s2[c];
		i++;
		c++;
	}
	str[i] = '\0';
	if (s1)
		free(s1);
	return (str);
}


