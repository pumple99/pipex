/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:55:01 by seunghoy          #+#    #+#             */
/*   Updated: 2022/11/21 18:23:47 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

static char	*ft_strdup_sep(char const *src, char c)
{
	int		i;
	char	*dup;

	i = 0;
	while (src[i] && src[i] != c)
		i++;
	dup = (char *)malloc(i + 1);
	if (dup == 0)
		return (0);
	i = 0;
	while (src[i] && src[i] != c)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

static char	**make_arr(char *str, char c)
{
	int		is_in_word;
	size_t	str_count;
	char	**str_arr;

	is_in_word = 0;
	str_count = 0;
	while (*str)
	{
		if (!is_in_word && *str != c)
		{
			is_in_word = 1;
			str_count++;
		}
		else if (is_in_word && *str == c)
			is_in_word = 0;
		str++;
	}
	str_arr = (char **)malloc(sizeof(char *) * (str_count + 1));
	if (str_arr)
		str_arr[str_count] = 0;
	return (str_arr);
}

static int	is_break_and_free(char **str_arr, int idx)
{
	int	i;

	if (str_arr[idx] == 0)
	{
		i = 0;
		while (i < idx)
			free(str_arr[i++]);
		free(str_arr);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		is_in_word;
	int		idx;
	char	**str_arr;

	str_arr = make_arr((char *)s, c);
	if (str_arr == 0)
		return (0);
	is_in_word = 0;
	idx = 0;
	while (*s)
	{
		if (!is_in_word && *s != c)
		{
			is_in_word = 1;
			str_arr[idx++] = ft_strdup_sep(s, c);
			if (is_break_and_free(str_arr, idx - 1))
				return (0);
		}
		else if (is_in_word && *s == c)
			is_in_word = 0;
		s++;
	}
	return (str_arr);
}

void	free_split_arr(char **str_arr)
{
	int	i;

	if (str_arr)
	{
		i = -1;
		while (str_arr[++i])
		{
			free(str_arr[i]);
		}
		free(str_arr);
	}
}
