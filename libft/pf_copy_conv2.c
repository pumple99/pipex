/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_copy_conv2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:37:09 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/26 17:37:13 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf.h"
#include "libft.h"

int	copy_c(char **temp, va_list *app, t_conv op)
{
	char	c;
	t_ull	t_len;

	t_len = 1;
	c = (char)va_arg(*app, int);
	copy_char(temp, ' ', op.width - t_len, !op.minus && op.width > t_len);
	copy_char(temp, c, 1, 1);
	copy_char(temp, ' ', op.width - t_len, op.minus && op.width > t_len);
	return (0);
}

int	copy_s(char **temp, va_list *app, t_conv op)
{
	char	*s;
	t_ull	t_len;

	s = (char *)va_arg(*app, char *);
	if (s == 0)
		s = "(null)";
	t_len = ft_strlen(s);
	if (op.point && op.preci < t_len)
		t_len = op.preci;
	copy_char(temp, ' ', op.width - t_len, !op.minus && op.width > t_len);
	copy_str(temp, s, t_len, 1);
	copy_char(temp, ' ', op.width - t_len, op.minus && op.width > t_len);
	return (0);
}

static	int	copy_di_zero(char **temp, int num, t_conv op)
{
	t_ull		t_len;
	long long	l_num;

	l_num = (long long)num;
	if (num < 0)
		l_num *= -1;
	t_len = get_ulen(num, op);
	if (num < 0 || op.plus || op.blank)
		t_len++;
	if (num < 0)
		copy_char(temp, '-', 1, 1);
	else if (op.blank)
		copy_char(temp, ' ', 1, 1);
	else if (op.plus)
		copy_char(temp, '+', 1, 1);
	copy_char(temp, '0', op.width - t_len, op.width > t_len);
	copy_num_base(temp, (t_ull)l_num, op);
	return (0);
}

int	copy_di(char **temp, va_list *app, t_conv op)
{
	long long	d;
	t_ull		t_len;

	d = (long long)va_arg(*app, int);
	if (op.zero)
		return (copy_di_zero(temp, (int)d, op));
	t_len = get_ulen((int)d, op);
	if (op.point && op.preci > t_len)
		t_len = op.preci;
	if (d < 0 || op.plus || op.blank)
		t_len++;
	copy_char(temp, ' ', op.width - t_len, !op.minus && op.width > t_len);
	if (d < 0)
		copy_char(temp, '-', 1, 1);
	else if (op.blank)
		copy_char(temp, ' ', 1, 1);
	else if (op.plus)
		copy_char(temp, '+', 1, 1);
	if (d < 0)
		d *= -1;
	if (op.point && op.preci > get_ulen((int)d, op))
		copy_char(temp, '0', op.preci - get_ulen((int)d, op), 1);
	copy_num_base(temp, d, op);
	copy_char(temp, ' ', op.width - t_len, op.minus && op.width > t_len);
	return (0);
}
