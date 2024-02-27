/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:49:24 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:49:23 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_isalpha : checks  for  an  alphabetic  character;  in  the  standard "C"
locale, it is equivalent to (isupper(c) || is‐lower(c)).
Return value :
- nonzero if the character c falls into the tested class
- zero if not.*/

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

/*#include <stdio.h>

int	main(void)
{
	printf("| ft_isalpha |\n");
	printf("1 == %d\n", ft_isalpha(100));
	printf("1 == %d\n", ft_isalpha(90));
	printf("0 == %d\n", ft_isalpha(43));
	printf("0 == %d\n", ft_isalpha(123));
	return (0);
}*/