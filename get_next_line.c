/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcela <marcela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:33:17 by marcela           #+#    #+#             */
/*   Updated: 2022/11/14 19:02:22 by marcela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*read -> ssize_t read(int fd, void *buf, size_t count)
le nbytes de um fd em um buffer comecando por buf
retorna 0 se chegou ao final do arquivo ou o numero de bytes 
lidos e -1 se tiver erro

buffer size -> quantos caracteres serao lidos por vez no read*/

char	*ft_read(int fd, char *str)
{
	char	*array;
	int		bytes;

	array = malloc((BUFFER_SIZE + 1) * sizeof(char)); //maloco o tamanho necessario para o buffer 
	if (!array)
		return (NULL);
	bytes = 1; //inicializo em 1 para entrar no loop pela primeira vez 
	while (!ft_strchr(str, '\n') && bytes != 0) //enquanto nao achar o \n e ainda tiver algo pra ler
	{
		bytes = read(fd, array, BUFFER_SIZE); //continuo guardando o retorno do read 
		if (bytes == -1) //se der erro no read 
		{
			free(array); //limpo o array 
			return (NULL);
		}
		array[bytes] = '\0'; //finalizo o buffer
		str = ft_free_join(str, array); //faco a juncao do que acabei de ler com o q ja tinha no str
	}
	free(array); //libero o array
	return (str); //retorno o str agr com a adicao de mais caracteres
}

char	*get_next_line(int fd)
{
	char             	*line; //a linha 
	static char     	*s; //static pq ele lembra onde parou da ultima vez qd a funcao e chamada

	if (fd < 0 || BUFFER_SIZE <= 0) //se fd for negativo e pq deu erro, e o buffer size menor ou igual a 0 nao le nada 
		return (NULL);
	s = ft_read(fd, s); //chamo a funcao que vai ler do buffer e guardo a nova str gerada em s
	if (!s) //se nao ler nada 
		return (NULL);
	line = ft_get_line(s); //a linha que vou usar agr
	s = ft_new_line(s); //guardo o que sobrou desse read
	return (line); //retorno a linha
}

/* int main()
{
	int fd = open("a.txt", O_RDONLY);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));

	return 0;
}   */