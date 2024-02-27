/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:19:54 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:50:43 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_lstsize : counts the number of nodes in a list.
Parameter : lst = the beginning of the list.
Return value : the length of the list.*/

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*tmp;

	size = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
/*#include <stdio.h>

int	main(void)
{
	t_list	*list;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	list = ft_lstnew(ft_strdup("Lundi"));
	node1 = ft_lstnew(ft_strdup("Mardi"));
	node2 = ft_lstnew(ft_strdup("Mercredi"));
	node3 = ft_lstnew(ft_strdup("Jeudi"));
	list->next = node1;
	node1->next = node2;
	node2->next = node3;
	printf("size of the list = %d", ft_lstsize(list));
	free (list->content);
	free (list);
	free (node1->content);
	free (node1);
	free (node2->content);
	free (node2);
	free (node3->content);
	free (node3);
}*/