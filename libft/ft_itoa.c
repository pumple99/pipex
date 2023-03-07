/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:10:28 by seunghoy          #+#    #+#             */
/*   Updated: 2022/11/21 17:19:00 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_get_itoa_len(long long nbr, int *is_minus)
{
	int	len;

	if (nbr == 0)
		return (1);
	len = 0;
	if (nbr < 0)
	{
		len++;
		nbr *= -1;
		*is_minus = 1;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			size;
	int			is_minus;
	long long	nbr;
	char		*itoa_str;

	nbr = (long long)n;
	is_minus = 0;
	size = ft_get_itoa_len(nbr, &is_minus);
	itoa_str = (char *)malloc(size + 1);
	if (itoa_str == 0)
		return (0);
	if (is_minus)
	{
		itoa_str[0] = '-';
		nbr *= -1;
	}
	itoa_str[size--] = 0;
	while (size >= is_minus)
	{
		itoa_str[size] = "0123456789"[nbr % 10];
		nbr /= 10;
		size--;
	}
	return (itoa_str);
}
