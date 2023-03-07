/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:15:35 by seunghoy          #+#    #+#             */
/*   Updated: 2022/11/21 18:11:43 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ss;
	size_t	t_len;
	size_t	ss_len;
	size_t	idx;

	t_len = ft_strlen(s);
	if (t_len <= start)
		ss_len = 0;
	else if (t_len < start + len)
		ss_len = t_len - start;
	else
		ss_len = len;
	ss = (char *)malloc(ss_len + 1);
	if (ss == 0)
		return (0);
	idx = 0 - 1;
	while (++idx < ss_len)
		ss[idx] = s[start + idx];
	ss[ss_len] = 0;
	return (ss);
}
