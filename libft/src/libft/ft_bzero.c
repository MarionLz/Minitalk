/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:34:38 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:49:07 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_bzero : erases the data in the n bytes of the memory starting at the
location pointed to by s, by writing zeros (bytes containing '\0') to that
area.
Return value : none.*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*#include <stdio.h>

int	main(void)
{
	printf("| ft_bzero |\n");
	char	s1[7] = "123456";

	ft_bzero(s1, 4);
	printf("rien == %s\n", s1);
	printf("56 == %s\n", s1+4);
}*/
