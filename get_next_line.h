/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:43:57 by anadal-g          #+#    #+#             */
/*   Updated: 2023/10/24 11:01:44 by anadal-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

size_t			ft_strlen(char *str);
char			*ft_strchr(char *s, int c);
char			*ft_strjoin(char *s1, char *s2);
char			*get_next_line(int fd);
char			*ft_get_line(char *save);
char			*ft_save(char *save);
char			*ft_read_and_save(int fd, char *save);
char			*free_line(char **line, void *tmp); 

#endif
