/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:00:36 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/26 17:38:36 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include "pf_printf.h"
#include "libft.h"

static int	print_pf(int fd, char *print_str, int err, t_ull pf_len)
{
	int	re;

	re = 0;
	if (err)
		re = err;
	else
	{
		if (pf_len > INT_MAX)
			re = ERR_RETURN_OVER;
		else
			re = (int)pf_len;
		if (write(fd, print_str, pf_len) < 0)
			re = ERR_WRITE;
	}
	free(print_str);
	return (re);
}

static t_ull	get_pf_len(const char *format, va_list *app, int *err)
{
	t_ull	len;
	va_list	ap;

	len = 0;
	va_copy(ap, *app);
	while (*format && !(*err))
	{
		if (*format != '%')
			len += get_plain_len(&format);
		else
			len += get_conv_len(&format, &ap, err);
	}
	va_end(ap);
	return (len);
}

static char	*get_pf_str(t_ull pf_len, int *err)
{
	char	*pf_str;

	if (*err)
		return (0);
	pf_str = malloc(pf_len + 1);
	if (pf_str == 0)
	{
		*err = ERR_MALLOC;
		return (0);
	}
	pf_str[pf_len] = 0;
	return (pf_str);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*print_str;
	char		*temp;
	int			err;
	t_ull		pf_len;

	err = 0;
	va_start(ap, format);
	pf_len = get_pf_len(format, &ap, &err);
	print_str = get_pf_str(pf_len, &err);
	temp = print_str;
	while (!err && *format)
	{
		if (*format != '%')
			err = copy_plain_str(&format, &temp);
		else
			err = copy_conv_str(&format, &temp, &ap);
	}
	va_end(ap);
	return (print_pf(1, print_str, err, pf_len));
}

int	fd_printf(int fd, const char *format, ...)
{
	va_list		ap;
	char		*print_str;
	char		*temp;
	int			err;
	t_ull		pf_len;

	err = 0;
	va_start(ap, format);
	pf_len = get_pf_len(format, &ap, &err);
	print_str = get_pf_str(pf_len, &err);
	temp = print_str;
	while (!err && *format)
	{
		if (*format != '%')
			err = copy_plain_str(&format, &temp);
		else
			err = copy_conv_str(&format, &temp, &ap);
	}
	va_end(ap);
	return (print_pf(fd, print_str, err, pf_len));
}
