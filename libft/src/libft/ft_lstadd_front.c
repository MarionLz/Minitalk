/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:05:07 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:50:11 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_lstadd_front : adds the node ’new’ at the beginning of the list.*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst == NULL)
		new->next = NULL;
	else
		new->next = *lst;
	*lst = new;
}

/*void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}
void	ft_print_list(t_list *list)
{
	while (list)
	{
		ft_putstr(list->content);
		ft_putstr("->");
		list = list->next;
	}
}
void	del_node(void *ptr)
{
	free(ptr);
}

#include <stdio.h>

int	main(void)
{
	t_list	*lst;
	t_list	*node1;
	t_list	*new;

	lst = ft_lstnew(ft_strdup("Lundi"));
	node1 = ft_lstnew(ft_strdup("Mardi"));
	new = ft_lstnew(ft_strdup("Mercredi"));
	lst->next = node1;
	ft_lstadd_front(&lst, new);
	ft_print_list(lst);
	ft_lstclear(&lst, del_node);
	return (0);
}*/