/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:23:38 by seunghoy          #+#    #+#             */
/*   Updated: 2023/03/08 19:59:40 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //exit
#include <unistd.h> //write
#include "../libft/libft.h"

int	err_exit(char *str)
{
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
	return (0);
}
