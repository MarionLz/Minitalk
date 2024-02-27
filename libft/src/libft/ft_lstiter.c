/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:57:22 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:50:22 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_lstier : iterates the list ’lst’ and applies the function ’f’ on the 
content of each node.*/

/*void	char_is_zero(void *ptr)
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
}*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
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
	ft_lstiter(lst, char_is_zero);
	ft_print_list(lst);
	free (lst->content);
	free (lst);
	free (node1->content);
	free (node1);
	free (node2->content);
	free (node2);
	return (0);
}*/