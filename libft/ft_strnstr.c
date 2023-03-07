/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:36:24 by seunghoy          #+#    #+#             */
/*   Updated: 2022/11/12 20:26:35 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;
	size_t	n_len;

	idx = 0;
	n_len = ft_strlen(needle);
	if (n_len == 0)
		return ((char *)haystack);
	if (len == 0)
		return (0);
	while (haystack[idx] && idx + n_len <= len)
	{
		if (!(ft_strncmp(haystack + idx, needle, n_len)))
			return ((char *)haystack + idx);
		idx++;
	}
	return (0);
}
