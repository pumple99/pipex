/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:17:08 by seunghoy          #+#    #+#             */
/*   Updated: 2022/11/12 19:32:06 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	idx;

	if (dstsize == 0)
		return (ft_strlen(src));
	idx = 0;
	dst_len = ft_strlen(dst);
	if (dst_len + 1 < dstsize)
	{
		while (src[idx] && dst_len + idx + 1 < dstsize)
		{
			dst[dst_len + idx] = src[idx];
			idx++;
		}
		dst[dst_len + idx] = 0;
	}
	if (dst_len > dstsize)
		return (dstsize + ft_strlen(src));
	return (dst_len + ft_strlen(src));
}
