/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:24:13 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:50:34 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_lstnew : allocates (malloc) and returns a new node. The member variable
’content’ is initialized with the value of the parameter ’content’.
The variable ’next’ is initialized to NULL.
Return value : the new node.*/

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	if (!content)
		new_node->content = NULL;
	else
		new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/*#include <stdio.h>

int	main(void)
{
	t_list	*new_node;
	char	*char_ptr;

	new_node = ft_lstnew("Lundi");
	char_ptr = (char *)new_node->content;
	printf("%s", char_ptr);
	free (new_node);
	return (0);
}*/