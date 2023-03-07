/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:21:34 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/26 17:34:54 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	return_index(char c)
{
	if ('0' <= c && c <= '9')
		return ((int)(c - '0'));
	return (-1);
}

static long long	make_int(const char *str, int is_minus)
{
	int			index;
	long long	num;

	index = 0;
	num = 0;
	while (return_index(str[index]) != -1)
	{
		num *= 10;
		if (is_minus)
			num -= return_index(str[index]);
		else
			num += return_index(str[index]);
		index++;
	}
	return (num);
}

long long	ft_atoi(const char *str)
{
	int	is_minus;
	int	index;	

	is_minus = 0;
	index = 0;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			is_minus++;
		index++;
	}
	return (make_int(str + index, is_minus));
}
