/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:14:04 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:52:30 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_substr : allocates (malloc) and returns a substring from the string ’s’.
The substring begins at index ’start’ and is of maximum size ’len’.
Return value : pointer to the string or NULL if allocation fails.*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	size_s;
	char			*sub;

	i = 0;
	size_s = ft_strlen(s);
	if (len > (size_s - start))
		len = (size_s - start);
	if (start >= size_s || size_s == 0)
		len = 0;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (i < len && s[i])
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

/*#include <stdio.h>

int	main(void)
{
	printf("| ft_substr |\n");
	char 	s[17] = "";
	char	*sub;

	sub = ft_substr(s, 0, 0);
	printf("%s", sub);
	free(sub);
}*/