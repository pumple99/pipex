/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:19:17 by seunghoy          #+#    #+#             */
/*   Updated: 2022/11/21 17:24:44 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	t_len;
	size_t	idx;
	char	*n_str;

	t_len = ft_strlen(s);
	n_str = (char *)malloc(t_len + 1);
	if (n_str == 0)
		return (0);
	idx = 0 - 1;
	while (++idx < t_len)
		n_str[idx] = f(idx, s[idx]);
	n_str[t_len] = 0;
	return (n_str);
}
