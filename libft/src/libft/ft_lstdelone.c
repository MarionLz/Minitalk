/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:45:48 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:50:18 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_lstdelone : takes as a parameter a node and frees the memory of the node’s
content using the function ’del’ given as a parameter and free the node.
The memory of ’next’ must not be freed.*/

void	del_node(void *ptr)
{
	free(ptr);
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}

/*#include <stdio.h>

int	main(void)
{
	t_list	*node;

	node = ft_lstnew(ft_strdup("Bonjour"));
	printf("Contenu du noeud avant : %s\n", (char *)node->content);
	ft_lstdelone(node, del_node);
}*/