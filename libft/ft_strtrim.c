/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:51:24 by seunghoy          #+#    #+#             */
/*   Updated: 2022/11/21 17:51:44 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

static int	is_instr(char c, char const *set)
{
	int	idx;

	idx = 0;
	while (set[idx])
	{
		if (c == set[idx])
			return (1);
		idx++;
	}
	return (0);
}

static size_t	len_cal(char const *s1, char const *set, \
		size_t *p_len, size_t *s_len)
{
	size_t	t_len;

	t_len = ft_strlen(s1);
	while (s1[*p_len] && is_instr(s1[*p_len], set))
		(*p_len)++;
	while (*s_len < t_len && is_instr(s1[t_len - *s_len - 1], set))
		(*s_len)++;
	return (t_len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	t_len;
	size_t	p_len;
	size_t	s_len;
	size_t	idx;
	char	*st;

	p_len = 0;
	s_len = 0;
	t_len = len_cal(s1, set, &p_len, &s_len);
	if (t_len < p_len + s_len)
		st = (char *)malloc(1);
	else
		st = (char *)malloc(t_len - p_len - s_len + 1);
	if (st == 0)
		return (0);
	idx = 0 - 1;
	while (++idx + p_len + s_len < t_len)
		st[idx] = s1[p_len + idx];
	st[idx] = 0;
	return (st);
}
