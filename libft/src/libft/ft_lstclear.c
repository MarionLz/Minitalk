/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:31:18 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:50:15 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_lstclear : deletes and frees the given node and every successor of that
node, using the function ’del’ and free(3). Finally, the pointer to the list
must be set to NULL.*/

/*void	del_node(void *ptr)
{
	free(ptr);
}*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node_next;

	while (*lst != NULL)
	{
		node_next = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = node_next;
	}
	lst = NULL;
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

int	main(void)
{
	t_list	*lst;
	t_list	*node1;
	t_list	*node2;

	lst = ft_lstnew(ft_strdup("Lundi"));
	node1 = ft_lstnew(ft_strdup("Mardi"));
	node2 = ft_lstnew(ft_strdup("Mercredi"));
	lst->next = node1;
	node1->next = node2;
	ft_lstclear(&lst, del_node);
	ft_print_list(lst);
	return (0);
}*/