/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maax <maax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:05:07 by malauzie          #+#    #+#             */
/*   Updated: 2024/02/16 10:55:50 by maax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_strjoin : allocates (malloc) and returns a new string, which is the result
of the concatenation of ’s1’ (prefix) and ’s2’ (suffix).
Return value : pointer to the new string or NULL if the allocation fails.*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	i = 0;
	j = 0;
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

/*#include <stdio.h>

int	main(void)
{
	printf("| ft_strjoin |\n");
	char	*str;

	str = ft_strjoin("Allo ", "Allo");
	printf("Allo Allo == %s\n", str);
	free(str);
	str = ft_strjoin("", "Bonjour");
	printf("Bonjour == %s\n", str);
	free(str);
}*/