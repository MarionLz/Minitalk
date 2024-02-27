/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:25:31 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:51:01 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_memset : fills the first n bytes of the memory area pointed to by s with
the constant byte c.
Return value : pointer to s.*/

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (ptr);
}

/*#include <stdio.h>

int	main(void)
{
	printf("| ft_memset |");
	int str[4];
	int i;
	
	ft_memset(&str, 67, sizeof(str));
	i = 0;
	while (i < 4)
	{
		printf("C == %c\n", str[i]);
		i++;
	}
	return (0);
}*/