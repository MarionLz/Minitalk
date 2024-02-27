/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:06:36 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:49:16 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_isalnum : checks for an alphanumeric character; it is equivalent to
(isalpha(c) || isdigit(c)).
Return value :
- nonzero if the character c falls into the tested class
- zero if not.*/

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
		return (1);
	return (0);
}

/*#include <stdio.h>

int	main(void)
{
	printf("| ft_isalnum |\n");
	printf("0 == %d\n", ft_isalnum('~'));
	printf("0 == %d\n", ft_isalnum(','));
    printf("1 == %d\n", ft_isalnum('5'));
    printf("1 == %d\n", ft_isalnum('F'));
	return (0);
}*/
