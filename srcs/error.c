/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:23:38 by seunghoy          #+#    #+#             */
/*   Updated: 2023/03/07 17:23:40 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/pf_printf.h"

int	insufficient_argu(void)
{
	fd_printf(2, "zsh: parse error near `\n'");
	return (0);
}
