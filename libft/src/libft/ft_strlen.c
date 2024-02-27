/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:17:48 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:52:05 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_strlen : calculates the length of the string pointed to by s, excluding
the terminating null byte ('\0').
Return value : the number of bytes in the string pointed to by s.*/

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*#include <stdio.h>

int	main(void)
{
	printf("| ft_strlen |\n");
	printf("6 == %ld\n", ft_strlen("Coucou"));
	printf("0 == %ld\n", ft_strlen(""));
	return (0);
}*/
