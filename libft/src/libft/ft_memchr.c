/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:08:54 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:50:47 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_memchr : scans the initial n bytes of the memory area pointed to by s for
the first instance of c. Both c and the bytes of the memory area pointed to by
s are interpreted as unsigned char.
Return value :
- pointer to the matching byte
- NULL if the character does not occur in the given memory area.*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	ptr = (char *)s;
	while (i < n)
	{
		if (ptr[i] == (char)c)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>

int	main(void)
{
	printf("| ft_memchr |\n");

	char bloc[] = {56, 49, 62, 56, 78, 104};
	char *ptr;

	ptr = ft_memchr(&bloc, 62, 4);
	printf(">8Nh == %s\n", ptr);
	ptr = ft_memchr(&bloc, 13, 4);
	printf("(null) == %s\n", ptr);
	return (0);
}*/