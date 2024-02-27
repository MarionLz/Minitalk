/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:11:03 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:52:00 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_strlcpy : copies up to size - 1 characters from the NUL-terminated string
src to dst, NUL-terminating the result. It take the full sizefull size of the
buffer (not just the length) and guarantee to NUL-terminate the result (as long
as size is larger than 0.
Return value : the total of src. */

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size != 0)
	{
		while (i < (size - 1) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/*#include <stdio.h>

int	main(void)
{
	printf("| ft_strlcpy |\n");
	char	src1[12] = "Hello World";
	char	dest1[5] = "allo";
	char	src2[7] = "123456";
	char	dest2[17] = "bonjour les gens";

	printf("11 == %ld\n", ft_strlcpy(dest1, src1, sizeof(dest1)));
	printf("Hell == %s\n", dest1);
	printf("6 == %ld\n", ft_strlcpy(dest2, src2, sizeof(dest2)));
	printf("123456 == %s\n", dest2);

	char	dest[15] = "000000000000000";
	printf("%ld\n", ft_strlcpy(dest, "", 15));
	printf("%s", dest);
}*/