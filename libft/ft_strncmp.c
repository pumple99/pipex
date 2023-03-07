/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:30:58 by seunghoy          #+#    #+#             */
/*   Updated: 2022/11/12 19:17:35 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				idx;
	const unsigned char	*us1;
	const unsigned char	*us2;

	us1 = (const unsigned char *)s1;
	us2 = (const unsigned char *)s2;
	idx = 0;
	if (n == 0)
		return (0);
	while ((us1[idx] || us2[idx]) && idx + 1 < n && us1[idx] == us2[idx])
		idx++;
	return (us1[idx] - us2[idx]);
}
