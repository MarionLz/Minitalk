/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:43:47 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:51:43 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_strchr : locate the first occurence of the character c in the string s.
Return value :
- pointer to the matched character
- NULL if the character is not found.*/

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

/*#include <stdio.h>

int	main(void)
{
	printf("| ft_strchr |\n");
	printf("i il fait beau. == %s\n", ft_strchr("Chez moi il fait beau.", 'i'));
	printf("(null) == %s\n", ft_strchr("Chez moi il fait beau.", 'd'));
	printf(" == %s\n", ft_strchr("Chez mo\0i il\0 fait \0beau.", '\0'));
	printf(" == %s\n", ft_strchr("Chez moi il fait beau.", '\0'));
	return (0);
}*/