/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:44:39 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:50:50 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_memcmp : compares the first n bytes (each interpreted as unsigned char) of
the memory areas s1 and s2.
Return value :
- int < 0 if first n bytes of s1 < s2
- int > 0 if first n bytes of s1 > s2
- int = 0 if first n bytes of s1 = s2
- 0 if n = 0.*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	i = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < (n - 1) && ptr1[i] == ptr2[i])
		i++;
	return (ptr1[i] - ptr2[i]);
}
/*int	main(void)
{
	printf("| ft_memcmp |");
	char bloc1[] = {121, 49, 63};
	char bloc2[] = {121, 100, 41};
	printf("-51 == %d\n", ft_memcmp(&bloc1, &bloc2, 3));
	char bloc3[] = {121, 100, 10};
	char bloc4[] = {121, 100, 63};
	printf("0 == %d\n", ft_memcmp(&bloc3, &bloc4, 2));
	char bloc5[] = {121, 100, 63};
	char bloc6[] = {121, 100, 41};
	printf("22 == %d\n", ft_memcmp(&bloc5, &bloc6, 3));
	char bloc7[] = {121, 100, 63};
	char bloc8[] = {121, 22, 41};
	printf("0 == %d\n", ft_memcmp(&bloc7, &bloc8, 0));
}*/
