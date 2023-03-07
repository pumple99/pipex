/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:43:14 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/19 13:39:37 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				idx;
	unsigned char		*new_dst;
	const unsigned char	*new_src;

	idx = 0;
	new_dst = (unsigned char *)dst;
	new_src = (const unsigned char *)src;
	if (dst == 0 && src == 0)
		return (dst);
	while (idx < n)
	{
		new_dst[idx] = new_src[idx];
		idx++;
	}
	return (dst);
}
