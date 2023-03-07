/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_copy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:36:49 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/26 17:36:51 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf.h"
#include "libft.h"

int	copy_plain_str(const char **format, char **temp)
{
	t_ull	len;

	len = get_plain_len(format);
	ft_memmove(*temp, *format - len, len);
	*temp += len;
	return (0);
}

int	copy_conv_str(const char **format, char **temp, va_list *app)
{
	t_conv	op;
	int		err;

	(*format)++;
	ft_memset(&op, 0, sizeof(t_conv));
	err = parse_format(format, &op);
	if (err)
		return (err);
	if (op.speci == 'c')
		return (copy_c(temp, app, op));
	else if (op.speci == 's')
		return (copy_s(temp, app, op));
	else if (op.speci == 'd' || op.speci == 'i')
		return (copy_di(temp, app, op));
	else if (op.speci == 'p')
		return (copy_p(temp, app, op));
	else if (op.speci == 'u')
		return (copy_u(temp, app, op));
	else if (op.speci == 'x' || op.speci == 'X')
		return (copy_xs(temp, app, op));
	else if (op.speci == '%')
		return (copy_percent(temp, op));
	return (0);
}

void	copy_char(char **dst, char c, t_ull len, int con)
{
	t_ull	idx;

	if (con)
	{
		idx = 0;
		if (*dst == 0)
			return ;
		while (idx < len)
		{
			**dst = c;
			(*dst)++;
			idx++;
		}
	}
}

void	copy_str(char **dst, char *src, t_ull len, int con)
{
	t_ull	idx;

	if (con)
	{
		idx = 0;
		if (*dst == 0 || src == 0)
			return ;
		while (idx < len)
		{
			**dst = src[idx];
			(*dst)++;
			idx++;
		}
	}
}

void	copy_num_base(char **dst, t_ull num, t_conv op)
{
	int			size;
	int			size_copy;
	char		*base;

	base = BASE_D;
	if (op.speci == 'x' || op.speci == 'p')
		base = BASE_X;
	else if (op.speci == 'X')
		base = BASE_X_CAP;
	size = get_itoa_len(num, op);
	size_copy = size--;
	while (size >= 0)
	{
		(*dst)[size] = base[num % ft_strlen(base)];
		num /= ft_strlen(base);
		size--;
	}
	*dst += size_copy;
}
