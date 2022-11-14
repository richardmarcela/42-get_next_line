/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcela <marcela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:33:23 by marcela           #+#    #+#             */
/*   Updated: 2022/11/14 19:33:50 by marcela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//minhas funcoes para:
//calcular tamanho do array
size_t	ft_strlen(char *c)
{
	size_t	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i])
		i++;
	return (i);
}

//encontrar a primeira ocorrencia de um caracter 
char	*ft_strchr(char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)str + i);
}

//juntar strings 
char	*ft_free_join(char *s, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
	{
		s = (char *)malloc(1 * sizeof(char));
		s[0] = '\0';
	}
	if (!s || !buffer)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(s) + ft_strlen(buffer)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s)
		while (s[++i] != '\0')
			str[i] = s[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[ft_strlen(s) + ft_strlen(buffer)] = '\0';
	free(s);
	return (str);
}

//essa funcao pega a linha que vou usar dessa vez 
char	*ft_get_line(char *s)
{
	int		i;
	char	*str;

	i = 0;
	if (!s[i]) //se s estiver vazio 
		return (NULL);
	while (s[i] && s[i] != '\n') //enquanto nao acabar s e nao chegar no newline 
		i++;
	str = (char *)malloc((i + 2) * sizeof(char)); //aloco o tamanho da linha ate o primeiro \n ou EOF
	if (!str)
		return (NULL);
	i = 0; //volto o i para 0 para comecar a escrever do comeco 
	while (s[i] && s[i] != '\n') //enquanto tiver algo e for diferente de \n
	{
		str[i] = s[i]; //coloco no str 
		i++;
	}
	if (s[i] == '\n') //incluo o newline na nova str
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str); //retorno a linha 
}

//essa funcao pega o resto da ultima vez q get_next_line for chamado se existir  
char	*ft_new_line(char *s)
{
	int			i;
	int			j;
	char		*str;

	i = 0;
	while (s[i] && s[i] != '\n') //enquanto não chega no EOF ou no new line continua avancando na string
		i++;
	if (!s[i]) //se não existir
	{
		free(s); //limpo o pointer
		return (NULL);
	}
	str = (char *)malloc((ft_strlen(s) - i + 1) * sizeof(char)); //aloco espaco pro tamanho de s menos i para guardar o que restar dessa leitura mas que nao vai ser usado dessa vez 
	if (!str) //se der erro
		return (NULL);
	i++; //incluo o \n
	j = 0;
	while (s[i]) //enquanto ainda tiver algo no s
		str[j++] = s[i++]; //guardo no str 
	str[j] = '\0'; //finalizo com null byte
	free(s); //limpo s pq já não preciso dele pra nada já que já guardei em outro lugar (str)
	return (str); //retorno str
}