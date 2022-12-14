/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcela <marcela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:33:25 by marcela           #+#    #+#             */
/*   Updated: 2022/11/14 19:04:19 by marcela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

size_t	ft_strlen(char *c);

char	*ft_strchr(char *str, int c);
char	*ft_free_join(char *s1, char *s2);
char	*ft_new_line(char *s);
char	*ft_get_line(char *s);
char	*get_next_line(int fd);
char	*ft_read(int fd, char *str);

#endif