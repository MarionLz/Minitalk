/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:03:14 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:49:11 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_calloc : allocates memory for an array of nmemb elements of size bytes
each and returns a pointer to the allocated memory. The memory is set to zero.
If nmemb = 0 or size = 0 : calloc() returns either NULL, or a unique pointer
value that can later be successfully passed to free().*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned int	len;
	char			*ptr;

	len = nmemb * size;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	ptr = (char *)malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, len);
	return (ptr);
}

/*include <stdio.h>

int	main(void)
{
	printf("| ft_calloc |\n");
	int *ptr1;
	int *ptr2;
	int *ptr3;

	ptr1 = ft_calloc(0, 0);
	printf("(null) == %ls\n", ptr1);
	free(ptr1);
	ptr2 = ft_calloc(0, sizeof(int));
	printf("(null) == %ls\n", ptr2);
	free(ptr2);
	ptr3 = ft_calloc(10, 2);
	printf("rien == %ls\n", ptr3);
	free(ptr3);
}*/
