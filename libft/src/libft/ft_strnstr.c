/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:06:23 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:52:19 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_strnstr : locates the first occurrence of the null-terminated string little
in the string big, where not more than len characters are searched.
Characters that appear after a ‘\0’ character are not searched.
Return value :
- if little is empty : big is returned
- if little occurs nowhere in big : NULL is returned
- otherwise a pointer to the first character of the first occurrence of little
is returned.*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	i = 0;
	str = (char *)big;
	if (!*little)
		return (str);
	while (i < len && str[i])
	{
		if (str[i] == little[0])
		{
			j = 0;
			while (str[i + j] == little[j] && little[j] && (i + j) < len)
				j++;
			if (little[j] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>

int	main(void)
{
	printf("| ft_strnstr |\n");
	char	big1[19] = "Le clair est ciel.";
	char	little1[5] = "ciel";
	char	big2[16] = "Miam j'ai faim.";
	char	little2[5] = "fin";
	char	big3[7] = "Coucou";
	char	little3[5] = "";
	char	big4[12] = "Hello World";
	char	little4[6] = "World";

	printf("ciel. == %s\n", ft_strnstr(big1, little1, 19));
	printf("(null) == %s\n", ft_strnstr(big2, little2, 16));
	printf("Coucou == %s\n", ft_strnstr(big3, little3, 7));
	printf("(null) == %s\n", ft_strnstr(big4, little4, 5));
}*/
