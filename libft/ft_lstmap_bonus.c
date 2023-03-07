/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:38:49 by seunghoy          #+#    #+#             */
/*   Updated: 2022/11/23 15:38:53 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	new_con_clear(t_list **start, void *new_con, void (*del)(void *), \
		t_list *temp)
{
	if (temp == 0)
	{
		del(new_con);
		ft_lstclear(start, del);
		return (1);
	}
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*last;
	t_list	*temp;
	void	*con;

	if (lst == 0)
		return (0);
	con = f(lst->content);
	start = ft_lstnew(con);
	if (new_con_clear(&start, con, del, start))
		return (0);
	last = start;
	while (lst->next)
	{
		lst = lst->next;
		con = f(lst->content);
		temp = ft_lstnew(con);
		if (new_con_clear(&start, con, del, temp))
			return (0);
		ft_lstadd_back(&last, temp);
		last = last->next;
	}
	return (start);
}
