/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:45:22 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:52:22 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_strrchr : locates the last occurence of the character c in the string s.
Return value : pointer to the matched character or NULL if the character is
not found.*/

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

/*#include <stdio.h>

int	main(void)
{
	printf("| ft_strrchr |\n");
	printf("it beau. == %s\n", ft_strrchr("Chez moi il fait beau.", 'i'));
	printf("(null) == %s\n", ft_strrchr("Chez moi il fait beau.", 'C'));
	printf("(null) == %s\n", ft_strrchr("Chez moi il fait beau.", 'd'));
	return (0);
}*/
