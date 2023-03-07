/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:09:46 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/19 13:40:23 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			n;
	unsigned char	*new_b;
	unsigned char	new_c;

	n = 0;
	new_b = (unsigned char *)b;
	new_c = (unsigned char)c;
	while (n < len)
	{
		*(new_b++) = new_c;
		n++;
	}
	return (b);
}
