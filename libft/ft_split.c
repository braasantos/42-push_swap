/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjorge-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:08:41 by bjorge-m          #+#    #+#             */
/*   Updated: 2023/10/27 12:31:24 by bjorge-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(char const *str, char c)
{
	int	i;
	int	flag;
	int	count;

	i = 0;
	flag = 1;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			flag = 0;
		else 
		{
			if (flag == 1)
			{
				count++;
				flag = 0;
			}
		}
		i++;
	}
	return (count);
}

char	**ft_getarr(char const *s, char **str, char c)
{
	int	i;
	int	j;
	int	k;
	char	**newarr;
	
	newarr = str;
	if (!newarr)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			newarr = (char **)ft_calloc(*s + 1, sizeof(char));
			newarr[j][k] = s[i];
			k++;
			i++;
		}
		newarr[j][k] = '\0';
		j++;
		i++;
	}
	newarr[j] = NULL;
	return (newarr);
}

char	**ft_split(char const *str, char c)
{
	char	**arr;
	arr =(char **)ft_calloc(ft_countwords(str, c) + 1, sizeof(char *));
	ft_getarr(str, arr, c);
	return (arr);
}
