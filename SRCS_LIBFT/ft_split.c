/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregada- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:27:21 by mregada-          #+#    #+#             */
/*   Updated: 2025/04/29 19:36:41 by mregada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	contador_letras(char const *s, char c)
{
	int	letras;

	letras = 0;
	while (s[letras] != c && s[letras])
	{
		letras++;
	}
	return (letras);
}

static int	contador_palabras(char const *s, char c)
{
	int	num;
	int	bandera;

	num = 0;
	bandera = 0;
	while (*s != '\0')
	{
		if (*s != c && !bandera)
		{
			bandera = 1;
			num++;
		}
		else if (*s == c && bandera)
			bandera = 0;
		s++;
	}
	return (num);
}

static char	*asignar_palabra(const char *s, int len)
{
	char	*palabra;
	int		i;

	palabra = malloc((len + 1) * sizeof(char));
	if (palabra == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		palabra[i] = s[i];
		i++;
	}
	palabra[len] = '\0';
	return (palabra);
}

static int	analizar_palabras(char const*s, char c, char **resultado)
{
	int		si;
	int		len_letras;
	size_t	ri;

	si = 0;
	ri = 0;
	while (s[si])
	{
		while (s[si] == c)
			si++;
		if (s[si] == '\0')
			break ;
		len_letras = contador_letras(&s[si], c);
		resultado[ri] = asignar_palabra(&s[si], len_letras);
		if (!resultado[ri])
			return (0);
		ri++;
		si = si + len_letras;
	}
	resultado[ri] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**resultado;
	int		n;
	int		i;

	if (!s)
		return (NULL);
	n = contador_palabras(s, c);
	resultado = malloc((n + 1) * sizeof(char *));
	if (!resultado)
		return (NULL);
	i = analizar_palabras (s, c, resultado);
	if (i == 0)
	{
		free (resultado);
		return (NULL);
	}
	return (resultado);
}
