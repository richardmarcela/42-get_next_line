/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcela <marcela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:33:17 by marcela           #+#    #+#             */
/*   Updated: 2022/11/09 11:30:37 by marcela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*read -> ssize_t read(int fd, void *buf, size_t count)
le nbytes de um fd em um buffer comecando por buf
retorna 0 se chegou ao final do arquivo ou o numero de bytes 
lidos e -1 se tiver erro*/

char *get_next_line(int fd)
{
    int             count;
    int             i;
    char            *buffer;
    static char     **s;

    if (fd < 0)
        return (-1);

    i = 0;
    buffer[0] = '\0'; //inicializo o buffer 
    count = read(fd, buffer, BUFFER_SIZE);
    while (count > 0)
    {
       buffer[0] = 
       s[0] = buffer[] 
    }
}