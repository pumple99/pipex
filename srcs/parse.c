/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:06:46 by seunghoy          #+#    #+#             */
/*   Updated: 2023/03/03 20:06:51 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //malloc, free
#include "../pipex.h"

static int	get_new_state(int prev_state, char c)
{
	if (prev_state == 0)
	{
		if (c == '\'')
			return (2);
		else if (c == '\"')
			return (3);
		else if (c != ' ')
			return (1);
	}
	else if (prev_state == 1)
	{
		if (c == '\'')
			return (2);
		else if (c == '\"')
			return (3);
		else if (c == ' ')
			return (0);
	}
	if (prev_state == 2 && c == '\'')
		return (1);
	if (prev_state == 3 && c == '\"')
		return (1);
	return (prev_state);
}

/*cmd: pipex command with options, never null
return: string array, last value of array is null*/
static char	**make_arr(char *cmd)
{
	int		state;
	int		new_state;
	int		str_count;
	char	**str_arr;

	state = 0;
	str_count = 0;
	while (*cmd)
	{
		new_state = get_new_state(state, *(cmd++));
		if (state == 0 && new_state != 0)
			++str_count;
		state = new_state;
	}
	str_arr = (char **)malloc(sizeof(char *) * (str_count + 1));
	if (str_arr)
		str_arr[str_count] = 0;
	return (str_arr);
}

/*src: word's starting address, not a start of total cmd input
return: size of string, not include " and '*/
static int	get_str_size(char *src)
{
	int		str_size;
	int		new_state;
	int		state;

	state = 0;
	str_size = 0;
	while (*src)
	{
		new_state = get_new_state(state, *(src++));
		if (new_state == 0)
			break ;
		if ((state == 0 && new_state == 1) || state == new_state)
			str_size++;
		state = new_state;
	}
	return (str_size);
}

/*src: word's starting address, not a start of total cmd input
return: copied string, not include " and '*/
static char	*copy_str_in_cmd(char *src)
{
	int		state;
	int		new_state;
	int		str_size;
	int		str_idx;
	char	*copy_str;

	state = 0;
	str_idx = 0;
	str_size = get_str_size(src);
	copy_str = (char *)malloc(str_size + 1);
	if (copy_str == 0)
		return (0);
	copy_str[str_size] = '\0';
	while (*src)
	{
		new_state = get_new_state(state, *src);
		if (new_state == 0)
			break ;
		if ((state == 0 && new_state == 1) || (state == new_state))
			copy_str[str_idx++] = *src;
		state = new_state;
		++src;
	}
	return (copy_str);
}

/*cmd: pipex command with options, never null
return: parsed string array, 0 when error*/
char	**parse_cmd(char *cmd)
{
	char	**str_arr;
	int		state;
	int		new_state;
	int		arr_idx;

	str_arr = make_arr(cmd);
	if (str_arr == 0)
		return (0);
	state = 0;
	arr_idx = 0;
	while (*cmd)
	{
		new_state = get_new_state(state, *cmd);
		if (state == 0 && new_state != 0)
		{
			str_arr[arr_idx++] = copy_str_in_cmd(cmd);
			if (str_arr[arr_idx - 1] == 0)
				return (free_parse_arr(str_arr, arr_idx - 1));
		}
		state = new_state;
		++cmd;
	}
	return (str_arr);
}
