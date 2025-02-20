/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:37:27 by emehdaou          #+#    #+#             */
/*   Updated: 2024/11/26 16:14:16 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

// int	count_letter(char const *str, char c, int *k)
// {
// 	int	i;

// 	*k = 0;
// 	i = 0;
// 	while (str[i] && str[i] != c)
// 		i++;
// 	return (i);
// }

// int	count_words(char const *str, char c, int *j, int *i)
// {
// 	int	l;
// 	int	cnt;

// 	l = 0;
// 	*i = 0;
// 	*j = 0;
// 	cnt = 0;
// 	while (str[l])
// 	{
// 		if (str[l] != c)
// 		{
// 			cnt++;
// 			while (str[l] && str[l] != c)
// 				l++;
// 		}
// 		else
// 			l++;
// 	}
// 	return (cnt);
// }

// void	free_tab(char **tab)
// {
// 	int	i;

// 	i = 0;
// 	while (tab[i])
// 		free(tab[i++]);
// 	free(tab);
// }

// char	**ft_split(char const *str, char c)
// {
// 	int		i;
// 	int		j;
// 	int		k;
// 	char	**res;

// 	if (!str)
// 		return (NULL);
// 	res = ft_calloc(sizeof(char *), count_words((char *)str, c, &j, &i) + 1);
// 	if (!res)
// 		return (free(res), NULL);
// 	while (str[i])
// 	{
// 		if (str[i] != c)
// 		{
// 			res[j] = ft_calloc(sizeof(char), count_letter(&str[i], c, &k) + 1);
// 			if (!res[j])
// 				return (free_tab(res), NULL);
// 			while (str[i] && str[i] != c)
// 				res[j][k++] = str[i++];
// 			j++;
// 		}
// 		else
// 			i++;
// 	}
// 	return (res);
// }

#include <stddef.h>
#include <stdlib.h>

// #include <stdio.h>

int	in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_letter(char const *str, char *charset, int *k)
{
	int	i;

	*k = 0;
	i = 0;
	while (str[i] && !in_charset(str[i], charset))
		i++;
	return (i);
}

int	count_words(char const *str, char *charset, int *j, int *i)
{
	int	l;
	int	cnt;

	l = 0;
	*i = 0;
	*j = 0;
	cnt = 0;
	while (str[l])
	{
		if (!in_charset(str[l], charset))
		{
			cnt++;
			while (str[l] && !in_charset(str[l], charset))
				l++;
		}
		else
			l++;
	}
	return (cnt);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		k;
	char	**res;

	res = malloc(sizeof(char *) * (count_words(str, charset, &j, &i) + 1));
	if (!res)
		return (free(res), NULL);
	while (str[i])
	{
		if (!in_charset(str[i], (char *)charset))
		{
			res[j] = malloc(sizeof(char) * (count_letter(&str[i],
							(char *)charset, &k) + 1));
			if (!res[j])
				return (free_tab(res), NULL);
			while (str[i] && !in_charset(str[i], (char *)charset))
				res[j][k++] = str[i++];
			res[j++][k] = '\0';
		}
		else
			i++;
	}
	res[j] = NULL;
	return (res);
}
