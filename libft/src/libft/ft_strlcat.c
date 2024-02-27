/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:10:25 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:51:56 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_strlcat : appends the NUL-terminated string src to the end of dst. It take
the full size of the buffer (not just the length) and guarantee to NUL-terminate
the result (as long as size is larger than 0 or, in the case of strlcat(), as
long as there is at least one byte free in pacodst).
Return value : the initial length of dst plus the length of src.*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len_dst;

	i = 0;
	len_dst = ft_strlen(dst);
	j = len_dst;
	if (size <= len_dst)
		return (ft_strlen(src) + size);
	while (i < (size - len_dst - 1) && src[i])
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (len_dst + ft_strlen(src));
}

/*#include <stdio.h>

int	main(void)
{
	printf("| ft_strlcat |\n");
	char	src1[6] = "World";
	char	dest1[7] = "Hello ";
	char	src2[7] = "123456";
	char	dest2[5] = "abc";

	printf("%ld\n", ft_strlcat(dest1, "World", 2));
	printf("%s\n", dest1);
	printf("4 == %ld\n", ft_strlcat(dest2, src2, sizeof(dest2)));
	printf("abc1 == %s\n", dest2);

	char	dest[15] = "rrrrrr";
	printf("%ld\n", ft_strlcat(dest, "lor", 5));
	printf("%s\n", dest);
}*/