/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maax <maax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:36:22 by malauzie          #+#    #+#             */
/*   Updated: 2024/02/01 10:22:34 by maax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_split : allocates (malloc) and returns an array of strings obtained by
splitting ’s’ using the character ’c’ as a delimiter. The array must end with a
NULL pointer.
Return value :
- the array of new strings resulting from the split.
- NULL if the allocation fails.*/

static int	count_words(char const *s, char c)
{
	int	i;
	int	count_words;

	i = 0;
	count_words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count_words++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count_words);
}
static char **fill_tab(char const *s, char c, char **tab, int nb_words)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] && k < nb_words)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		tab[k] = ft_substr(s, j, i - j);
		k++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		nb_words;
	char	**tab;

	nb_words = count_words(s, c);
	tab = (char **)malloc((nb_words + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab = fill_tab(s, c, tab, nb_words);
	tab[nb_words] = NULL;
	return (tab);
}

/*#include <stdio.h>

int	main(void)
{
	printf("| ft_split |\n");

	int		i;
	char	**tab_split;
	char	*str_split = "xxxxxxxhello!";
	char	char_sep = 'x';

	i = 0;
	tab_split = ft_split(str_split, char_sep);

	while (i < ft_count_bloc(str_split, char_sep))
	{
		printf("%s\n", tab_split[i]);
		free (tab_split[i]);
		i++;
	}
	free (tab_split);
	
	int		i;
	char	**tab_split;
	char	char_sep = ' ';

	i = 0;
	if (argc == 2)
	{
		tab_split = ft_split(argv[1], char_sep);
		while (i < ft_count_bloc(argv[1], char_sep))
		{
			printf("%s\n", tab_split[i]);
			free (tab_split[i]);
			i++;
		}
	free (tab_split);
	}
}*/