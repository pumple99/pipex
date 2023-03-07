/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_copy_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:36:59 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/26 17:37:03 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf.h"

int	copy_p(char **temp, va_list *app, t_conv op)
{
	t_ull	p;
	t_ull	t_len;

	p = (t_ull)va_arg(*app, t_ull);
	t_len = (t_ull)get_itoa_len(p, op) + 2;
	copy_char(temp, ' ', op.width - t_len, !op.minus && op.width > t_len);
	copy_str(temp, "0x", 2, 1);
	copy_num_base(temp, p, op);
	copy_char(temp, ' ', op.width - t_len, op.minus && op.width > t_len);
	return (0);
}

int	copy_u(char **temp, va_list *app, t_conv op)
{
	t_ui	u;
	t_ull	t_len;
	char	c;

	c = ' ';
	if (op.zero)
		c = '0';
	u = (t_ui)va_arg(*app, t_ui);
	t_len = (t_ull)get_itoa_len((t_ull)u, op);
	if (op.point && op.preci > t_len)
		t_len = op.preci;
	copy_char(temp, c, op.width - t_len, !op.minus && op.width > t_len);
	if (op.point && op.preci > (t_ull)get_itoa_len((t_ull)u, op))
		copy_char(temp, '0', op.preci - (t_ull)get_itoa_len((t_ull)u, op), 1);
	copy_num_base(temp, (t_ull)u, op);
	copy_char(temp, c, op.width - t_len, op.minus && op.width > t_len);
	return (0);
}

static void	copy_hash(char **temp, t_conv op, int con)
{
	char	*str;

	str = "0x";
	if (op.speci == 'X')
		str = "0X";
	copy_str(temp, str, 2, con);
}

int	copy_xs(char **temp, va_list *app, t_conv op)
{
	t_ui	xs;
	t_ull	t_len;
	char	c;

	c = ' ';
	if (op.zero)
		c = '0';
	xs = (t_ui)va_arg(*app, t_ui);
	t_len = (t_ull)get_itoa_len((t_ull)xs, op);
	if (op.point && op.preci > t_len)
		t_len = op.preci;
	if (op.hash && xs)
		t_len += 2;
	copy_hash(temp, op, op.hash && xs && op.zero);
	copy_char(temp, c, op.width - t_len, !op.minus && op.width > t_len);
	copy_hash(temp, op, op.hash && xs && !op.zero);
	if (op.point && op.preci > (t_ull)get_itoa_len((t_ull)xs, op))
		copy_char(temp, '0', op.preci - (t_ull)get_itoa_len((t_ull)xs, op), 1);
	copy_num_base(temp, (t_ull)xs, op);
	copy_char(temp, c, op.width - t_len, op.minus && op.width > t_len);
	return (0);
}

int	copy_percent(char **temp, t_conv op)
{
	t_ull	t_len;
	char	c;

	c = ' ';
	if (op.zero)
		c = '0';
	t_len = 1;
	copy_char(temp, c, op.width - t_len, !op.minus && op.width > t_len);
	copy_char(temp, '%', t_len, 1);
	copy_char(temp, c, op.width - t_len, op.minus && op.width > t_len);
	return (0);
}
