/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:32:47 by seunghoy          #+#    #+#             */
/*   Updated: 2022/11/21 17:55:30 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	re_putnbr_fd(long long nbr, int fd)
{
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		re_putnbr_fd(-nbr, fd);
	}
	else
	{
		if (nbr >= 10)
		{
			re_putnbr_fd(nbr / 10, fd);
			ft_putchar_fd((char)(48 + nbr % 10), fd);
		}
		else
			ft_putchar_fd((char)(48 + nbr % 10), fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	re_putnbr_fd((long long)n, fd);
}
