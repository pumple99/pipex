/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:35:18 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/26 17:38:45 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_PRINTF_H
# define PF_PRINTF_H
# include <stdarg.h>

# define ERR_MALLOC -1
# define ERR_RETURN_OVER -2
# define ERR_WIDTH_OVER -3
# define ERR_PRECISION_OVER -4
# define ERR_WRITE -5
# define BASE_D "0123456789"
# define BASE_X "0123456789abcdef"
# define BASE_X_CAP "0123456789ABCDEF"

typedef unsigned long long	t_ull;
typedef unsigned int		t_ui;
typedef struct s_conv
{
	int		plus;
	int		minus;
	int		zero;
	int		blank;
	int		hash;
	int		point;
	t_ull	width;
	t_ull	preci;
	char	speci;
}	t_conv;

//pf_printf.c
int		ft_printf(const char *format, ...);
int		fd_printf(int fd, const char *format, ...);

//pf_len.c
t_ull	get_plain_len(const char **format);
t_ull	get_conv_len(const char **format, va_list *app, int *err);
int		get_itoa_len(t_ull nbr, t_conv op);
t_ull	get_slen(int num, t_conv op);
t_ull	get_ulen(int num, t_conv op);

//pf_len_conv.c
t_ull	conv_cpp_len(t_conv op, va_list *app);
t_ull	conv_s_len(t_conv op, va_list *app);
t_ull	conv_di_len(t_conv op, va_list *app);
t_ull	conv_u_len(t_conv op, va_list *app);
t_ull	conv_xs_len(t_conv op, va_list *app);

//pf_copy.c
int		copy_plain_str(const char **format, char **temp);
int		copy_conv_str(const char **format, char **temp, va_list *ap);
void	copy_char(char **dst, char c, t_ull len, int con);
void	copy_str(char **dst, char *src, t_ull len, int con);
void	copy_num_base(char **dst, t_ull num, t_conv op);

//pf_copy_conv.c
int		copy_p(char **temp, va_list *app, t_conv op);
int		copy_u(char **temp, va_list *app, t_conv op);
int		copy_xs(char **temp, va_list *app, t_conv op);
int		copy_percent(char **temp, t_conv op);

//pf_copy_conv2.c
int		copy_c(char **temp, va_list *app, t_conv op);
int		copy_s(char **temp, va_list *app, t_conv op);
int		copy_di(char **temp, va_list *app, t_conv op);

//pf_parse.c
int		parse_format(const char **format, t_conv *op);

#endif
