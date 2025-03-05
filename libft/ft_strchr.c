/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:31:17 by emehdaou          #+#    #+#             */
/*   Updated: 2025/03/05 16:29:41 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*s1;

	i = 0;
	s1 = (unsigned char *)s;
	while (i <= ft_strlen((char *)(s1)))
	{
		if (s1[i] == (unsigned char)c)
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
