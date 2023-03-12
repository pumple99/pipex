/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:06:46 by seunghoy          #+#    #+#             */
/*   Updated: 2023/03/12 16:29:49 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	prev_is_zero(char c)
{
	if (c == ' ')
		return (0);
	else if (c == '\'')
		return (2);
	else if (c == '\"')
		return (3);
	else if (c == '\\')
		return (4);
	else
		return (1);
}

static int	prev_is_one(char c)
{
	if (c == '\'')
		return (2);
	else if (c == '\"')
		return (3);
	else if (c == '\\')
		return (4);
	else if (c == ' ')
		return (0);
	return (1);
}

int	get_new_state(int prev_state, char c)
{
	if (prev_state == 0)
		return (prev_is_zero(c));
	else if (prev_state == 1)
		return (prev_is_one(c));
	if (prev_state == 2 && c == '\'')
		return (1);
	if (prev_state == 2 && c == '\\')
		return (5);
	if (prev_state == 3 && c == '\"')
		return (1);
	if (prev_state == 3 && c == '\\')
		return (6);
	if (prev_state > 3)
		return (prev_state - 3);
	return (prev_state);
}
