/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:03:26 by yassharm          #+#    #+#             */
/*   Updated: 2020/01/21 22:03:28 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

int			get_next_line(int fd, char **line);
size_t		ft_strlen(char *s);
char		*ft_strjoin(char *s1, char const *s2);
char		*ft_strdup(char *s1);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
int			check_newline(char *line);

#endif
