/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:06:57 by seunghoy          #+#    #+#             */
/*   Updated: 2023/03/03 20:07:01 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //free

/*str_arr: string array to be freed.
num: the number of strings to be freed,
if num == 0 free until str_arr[idx] == 0*/
char	**free_parse_arr(char **str_arr, int num)
{
	int	i;

	if (num == 0)
	{
		i = -1;
		while (str_arr[++i])
			free(str_arr[i]);
	}
	else
	{
		i = 0;
		while (i < num)
			free(str_arr[i++]);
	}
	free(str_arr);
	return (0);
}
