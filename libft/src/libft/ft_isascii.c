/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:09:25 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:49:28 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_isascii : checks whether c is a 7-bit unsigned char value that fits into
the ASCII character set.
Return value :
- nonzero if the character c falls into the tested class
- zero if not.*/

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*#include <stdio.h>

int	main(void)
{
	printf("| ft_isascii |\n");
	printf("1 == %d\n", ft_isascii(0));
	printf("1 == %d\n", ft_isascii(91));
	printf("0 == %d\n", ft_isascii(136));
	return (0);
}*/