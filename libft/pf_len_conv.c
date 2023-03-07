/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_len_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:37:35 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/26 17:37:37 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf.h"
#include "libft.h"

t_ull	conv_cpp_len(t_conv op, va_list *app)
{
	t_ull	t_len;

	t_len = 1;
	if (op.speci == 'c')
		va_arg(*app, int);
	else if (op.speci == 'p')
		t_len = (t_ull)get_itoa_len((t_ull)va_arg(*app, t_ull), op) + 2;
	if (op.width > t_len)
		t_len = op.width;
	return (t_len);
}

t_ull	conv_s_len(t_conv op, va_list *app)
{
	char	*s;
	t_ull	t_len;

	s = (char *)va_arg(*app, char *);
	if (s == 0)
		t_len = 6;
	else
		t_len = ft_strlen(s);
	if (op.point && op.preci < t_len)
		t_len = op.preci;
	if (op.width > t_len)
		t_len = op.width;
	return (t_len);
}

t_ull	conv_di_len(t_conv op, va_list *app)
{
	int		di;
	t_ull	t_len;

	di = (int)va_arg(*app, int);
	t_len = get_slen(di, op);
	if (di < 0)
		t_len--;
	if (op.point && op.preci > t_len)
		t_len = op.preci;
	if (di < 0 || op.blank || op.plus)
		t_len++;
	if (op.width > t_len)
		t_len = op.width;
	return (t_len);
}

t_ull	conv_u_len(t_conv op, va_list *app)
{
	t_ui	u;
	t_ull	t_len;

	u = (t_ui)va_arg(*app, t_ui);
	t_len = (t_ull)get_itoa_len((t_ull)u, op);
	if (op.point && op.preci > t_len)
		t_len = op.preci;
	if (op.width > t_len)
		t_len = op.width;
	return (t_len);
}

t_ull	conv_xs_len(t_conv op, va_list *app)
{
	t_ull	xs;
	t_ull	t_len;

	xs = (t_ull)(t_ui)va_arg(*app, t_ui);
	t_len = (t_ull)get_itoa_len(xs, op);
	if (op.point && op.preci > t_len)
		t_len = op.preci;
	if (xs > 0 && op.hash)
		t_len += 2;
	if (op.width > t_len)
		t_len = op.width;
	return (t_len);
}
