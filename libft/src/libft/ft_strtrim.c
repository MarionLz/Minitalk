/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 09:51:19 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:52:26 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_strtrim : Allocates (malloc) and returns a copy of ’s1’ with the characters
specified in ’set’ removed from the beginning and the end of the string.
Return value : pointer to the trimmed string or NULL if the allocation fails.*/

static int	ft_isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_copy_without_set(char const *s1, char *strim, size_t i,
								size_t len_strim)
{
	unsigned int	j;

	j = 0;
	while (j < len_strim)
		strim[j++] = s1[i++];
	strim[j] = '\0';
	return (strim);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	count;
	unsigned int	len_strim;
	char			*strim;

	i = 0;
	j = ft_strlen(s1) - 1;
	count = 0;
	while (ft_isset(s1[i], set))
		i++;
	if (i == ft_strlen(s1))
		return (ft_strdup(""));
	while (ft_isset(s1[j], set))
	{
		j--;
		count++;
	}
	len_strim = (ft_strlen(s1) - (count + i));
	strim = (char *)malloc((len_strim + 1) * sizeof(char));
	if (strim == NULL)
		return (NULL);
	return (ft_copy_without_set(s1, strim, i, len_strim));
}

/*#include <stdio.h>

int	main(void)
{
	printf("| ft_strtrim |");
	
	char	*strim;

	strim = ft_strtrim("  \t \t \n   \n\n\n\t", " \n\t");
	printf("%s", strim);
	free(strim);
}*/