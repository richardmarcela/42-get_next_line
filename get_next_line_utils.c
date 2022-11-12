/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrichard <mrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:33:23 by marcela           #+#    #+#             */
/*   Updated: 2022/11/12 14:34:42 by mrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//minhas funcoes para:
//calcular tamanho do array
size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

//encontrar a primeira ocorrencia de um caracter 
char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)str + i);
}

//juntar strings 
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*new_str;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1)
		return (NULL);
	i = 0;
	j = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (new_str == NULL)
		return (NULL);
	while (j < len_s1)
		new_str[i++] = s1[j++];
	j = 0;
	while (j < len_s2)
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	return (new_str);
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
	str = (char *)malloc(sizeof(char) * (i + 2)); //aloco o tamanho da linha ate o primeiro \n ou EOF
	if (!str) //se o malloc falhar 
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
	str[i] = '\0'; //finalizo com null byte
	return (str); //retorno a linha 
}

//essa funcao pega o resto da ultima vez q get_next_line for chamado se existir  
char	*ft_new_line(char *s)
{
	int			i;
	int			j;
	char		*str;

	i = 0;
	while (s[i] && s[i] != '\n') //enquanto no chega no EOF ou no new line continua avancando no string
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) - i + 1)); //aloco espaco pro tamanho de s menos i para guardar o que restar dessa leitura mas que nao vai ser usado dessa vez 
	if (!str) //se o malloc falhar
		return (NULL);
	i++; //incluo o \n
	j = 0; 
	while (s[i]) //enquanto ainda tiver algo no s
		str[j++] = s[i++]; //guardo no str 
	str[j] = '\0'; //finalizo com null byte
	free(s); //limpo s
	return (str); //retorno str
}