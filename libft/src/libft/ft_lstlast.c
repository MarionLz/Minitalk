/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:28:45 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:50:26 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_lstlast : returns the last node of the list.*/

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*#include <stdio.h>

void	del_node(void *ptr)
{
	free(ptr);
}

int	main(void)
{
	t_list	*lst;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*node4;
	t_list	*result;

	lst = ft_lstnew(ft_strdup("Lundi"));
	node1 = ft_lstnew(ft_strdup("Mardi"));
	node2 = ft_lstnew(ft_strdup("Mercredi"));
	node3 = ft_lstnew(ft_strdup("Jeudi"));
	node4 = ft_lstnew(ft_strdup("Vendredi"));
	lst->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	result = ft_lstlast(lst);
	printf("the last node of the list = %s", (char *)result->content);
	ft_lstclear(&lst, del_node);
	return (0);
}*/