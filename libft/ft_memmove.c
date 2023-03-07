/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:24:07 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/19 13:40:03 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				idx;

	idx = 0;
	if (dst == 0 && src == 0)
		return (dst);
	if (dst < src)
	{
		while (idx < len)
		{
			((unsigned char *)dst)[idx] = \
			((const unsigned char *)src)[idx];
			idx++;
		}
	}
	else
	{
		while (idx < len)
		{
			((unsigned char *)dst)[len - idx - 1] = \
			((const unsigned char *)src)[len - idx - 1];
			idx++;
		}
	}
	return (dst);
}
