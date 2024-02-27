/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:25:05 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:51:46 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_strdup : returns a pointer to a new string which is a duplicate of the
string s. Memory for the new string is obtained with malloc, and can be freed
with free.
Return value :
- a pointer to the duplicated string.
- NULL if insufficient memory was available.*/

char	*ft_strdup(const char *s)
{
	unsigned int	len;
	unsigned int	i;
	char			*dest;

	i = 0;
	len = ft_strlen(s);
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*#include <stdio.h>

int	main(void)
{
	printf("| ft_strdup |");

	char	*str;

	str = ft_strdup("Hello");
	printf("%s", str);
	free(str);
}*/