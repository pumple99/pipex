/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:37:48 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/26 17:37:50 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "pf_printf.h"
#include "libft.h"

static void	parse_flag(const char **format, t_conv *op)
{
	while (**format == '+' || **format == '-' || **format == '0' \
	|| **format == ' ' || **format == '#')
	{
		if (**format == '+')
		{
			op->plus = 1;
			op->blank = 0;
		}
		else if (**format == '-')
		{
			op->minus = 1;
			op->zero = 0;
		}
		else if (**format == '0' && !(op->minus))
			op->zero = 1;
		else if (**format == ' ' && !(op->plus))
			op->blank = 1;
		else if (**format == '#')
			op->hash = 1;
		(*format)++;
	}
}

static void	parse_width_precision(const char **format, t_conv *op)
{
	op->width = (t_ull)ft_atoi(*format);
	while ('0' <= **format && **format <= '9')
		(*format)++;
	if (**format == '.')
	{
		op->zero = 0;
		op->point = 1;
		(*format)++;
		op->preci = (t_ull)ft_atoi(*format);
		while ('0' <= **format && **format <= '9')
			(*format)++;
	}
}

static void	parse_specifier(const char **format, t_conv *op)
{
	if (**format == 'c' || **format == 's' || **format == 'p' || \
	**format == 'd' || **format == 'i' || **format == 'u' || \
	**format == 'x' || **format == 'X' || **format == '%')
	{
		op->speci = **format;
		(*format)++;
	}
}

int	parse_format(const char **format, t_conv *op)
{
	parse_flag(format, op);
	parse_width_precision(format, op);
	parse_specifier(format, op);
	if (op->width > INT_MAX)
		return (ERR_WIDTH_OVER);
	if (op->preci > INT_MAX)
		return (ERR_PRECISION_OVER);
	return (0);
}
