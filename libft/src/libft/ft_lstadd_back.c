/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:32:47 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:50:03 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_lstadd_back : adds the node ’new’ at the end of the list.*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (new)
	{
		if (*lst)
		{
			last_node = ft_lstlast(*lst);
			last_node->next = new;
		}
		else
			*lst = new;
	}
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

#include <stdio.h>

void	del_node(void *ptr)
{
	free(ptr);
}

int	main(void)
{
	t_list	*lst;
	t_list	*node1;
	t_list	*new;

	lst = ft_lstnew(ft_strdup("Lundi"));;
	node1 = ft_lstnew(ft_strdup("Mardi"));
	new= ft_lstnew(ft_strdup("Mercredi"));
	lst->next = node1;
	ft_lstadd_back(&lst, new);
	ft_print_list(lst);
	ft_lstclear(&lst, del_node);
	return (0);
}*/