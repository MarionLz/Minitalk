/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:33:02 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:50:54 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_memcpy : copies n bytes from memory area src to memory area dest.
In case of overlapping, use ft_memmove.
Return value : pointer to dest.*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (!s && !d)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

/*#include <stdio.h>

int	main(void)
{
	printf("| ft_memcpy |\n");
	char	src[7] = "";
	char	dest[7] = "";

	ft_memcpy(dest, src, 3);
	printf("12cdef == %s", dest);
}*/
