/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:13:21 by seunghoy          #+#    #+#             */
/*   Updated: 2022/11/21 15:52:45 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stddef.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			idx;
	unsigned char	uc;

	uc = (unsigned char)c;
	idx = 0;
	if (uc == 0)
		return ((char *)s + ft_strlen(s));
	while (s[idx])
	{
		if (s[idx] == uc)
			return ((char *)s + idx);
		idx++;
	}
	return (0);
}
