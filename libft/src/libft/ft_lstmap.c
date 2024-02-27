/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:13:03 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:50:29 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_lstmap : iterates the list ’lst’ and applies the function ’f’ on the
content of each node. Creates a new list resulting of the successive
applications of the function ’f’. The ’del’ function is used to delete the
content of a node if needed.
Return value : the new list or NULL if the allocation fails.*/

/*void	*char_is_zero(void *ptr)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)ptr;
	while (str[i])
	{
		str[i] = '0';
		i++;
	}
	return (str);
}

void	del_node(void *ptr)
{
	free(ptr);
}*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (!lst)
		return (NULL);
	new_list = ft_lstnew(f(lst->content));
	if (!new_list)
	{
		ft_lstclear(&new_list, del);
		return (NULL);
	}
	while (lst->next != NULL)
	{
		lst = lst->next;
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
	}
	return (new_list);
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

int	main(void)
{
	t_list	*lst;
	t_list	*node1;
	t_list	*node2;
	t_list	*new_list;

	lst = ft_lstnew(ft_strdup("Lundi"));
	node1 = ft_lstnew(ft_strdup("Mardi"));
	node2 = ft_lstnew(ft_strdup("Mercredi"));
	lst->next = node1;
	node1->next = node2;
	new_list = ft_lstmap(lst, char_is_zero, del_node);
	ft_print_list(new_list);
	ft_lstclear(&lst, del_node);
	ft_lstclear(&new_list, del_node);
	return (0);
}*/