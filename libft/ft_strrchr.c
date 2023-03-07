/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:59:34 by seunghoy          #+#    #+#             */
/*   Updated: 2022/11/21 15:53:21 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stddef.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			next;
	unsigned char	uc;

	uc = (unsigned char)c;
	next = ft_strlen(s) + 1;
	while (0 < next)
	{
		if (s[next - 1] == uc)
			return ((char *)s + next - 1);
		next--;
	}
	return (0);
}
