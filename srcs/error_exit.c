/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:23:38 by seunghoy          #+#    #+#             */
/*   Updated: 2023/03/12 17:41:45 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //exit
#include <stdio.h> //perror
#include <unistd.h> //write
#include "../libft/libft.h" //ft_strlen

int	err_exit(char *str)
{
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
	return (0);
}

int	perr_exit(char *str, int exit_status)
{
	perror(str);
	exit(exit_status);
	return (0);
}
