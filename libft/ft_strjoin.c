/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:42:05 by seunghoy          #+#    #+#             */
/*   Updated: 2022/11/21 16:51:12 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	idx;
	char	*sj;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	sj = (char *)malloc(len1 + len2 + 1);
	if (sj == 0)
		return (0);
	idx = 0 - 1;
	while (++idx < len1)
		sj[idx] = s1[idx];
	idx = 0 - 1;
	while (++idx < len2)
		sj[len1 + idx] = s2[idx];
	sj[len1 + len2] = 0;
	return (sj);
}
