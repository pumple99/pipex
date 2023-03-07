/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_err2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:15:53 by seunghoy          #+#    #+#             */
/*   Updated: 2023/03/07 17:15:56 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //exit free
#include <stdio.h> //perror

char	**check_malloc2(char **addr)
{
	if (addr)
		return (addr);
	perror("bash: malloc failed");
	exit(EXIT_FAILURE);
}

char	*check_malloc(char *addr)
{
	if (addr)
		return (addr);
	perror("bash: malloc failed");
	exit(EXIT_FAILURE);
}
