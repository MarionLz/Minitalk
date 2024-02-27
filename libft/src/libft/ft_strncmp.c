/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:12:00 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:52:15 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_strncmp : compares the first n bytes of s1 and s2.
Return value :
- int < 0 if first n bytes of s1 < s2
- int > 0 if first n bytes of s1 > s2
- int = 0 if first n bytes of s1 = s2
- 0 if n = 0.*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 && *s2 && *s1 == *s2)
	{
		n--;
		s1++;
		s2++;
	}
	if (n == 0)
		return (0);
	return ((int)((unsigned char)*s1 - (unsigned char)*s2));
}

/*#include <stdio.h>

int	main(void)
{
	printf("| ft_strncmp |\n");
	printf("0 == %d\n", ft_strncmp("\200", "\0", 1));
	printf("0 == %d\n", ft_strncmp("Allo", "Alla", 3));
	printf("-7 == %d\n", ft_strncmp("Allo", "Hola", 2));
	printf("6 == %d\n", ft_strncmp("Hola", "Bonjour", 3));
	return (0);
}*/
