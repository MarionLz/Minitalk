/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:36:58 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:50:58 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_memmove : copies n bytes from memory area src to memory area dest.
This function handles overlap : if dest(adress) > src(adress), bytes are copying
from the end of dest & src.
Return value : pointer to dest. */

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (!s && !d)
		return (NULL);
	if (d > s)
	{
		d = d + n - 1;
		s = s + n - 1;
		while (n--)
			*d-- = *s--;
	}
	else
	{
		while (n--)
			*d++ = *s++;
	}
	return (dest);
}
/*#include <stdio.h>

int	main(void)
{
	printf("| ft_memmove |\n");
	char s1[20] = "123456";
	char s2[20] = "Hello World";
	char d[20] = "Bonjour";

	ft_memmove(s1+2 ,s1 ,2);
	printf("1256 == %s\n",s1+2);
	ft_memmove(s1 ,s1+3 ,3);
	printf("256256 == %s\n",s1);
	ft_memmove(d ,s2 ,2);
	printf("Henjour == %s\n",d);
}*/