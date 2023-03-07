/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:48:27 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/19 13:40:41 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				idx;
	const unsigned char	*cs;
	unsigned char		cc;

	idx = 0;
	cs = (const unsigned char *)s;
	cc = (unsigned char)c;
	while (idx < n)
	{
		if (cs[idx] == cc)
			return ((void *)(cs + idx));
		idx++;
	}
	return (0);
}
