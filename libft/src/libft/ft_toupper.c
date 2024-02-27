/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:32:16 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:52:37 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_toupper : If c is a lowercase letter, toupper() returns its uppercase
equivalent, if an uppercase representation exists in the current locale.
Return value : the converted letter or c if the conversion is not possible.*/

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c = c - 32;
	return (c);
}

/*#include <stdio.h>

int	main(void)
{
	printf("| ft_toupper |\n");
	printf("65 == %d\n", ft_toupper(97));
	printf("74 == %d\n", ft_toupper(106));
	printf("45 == %d\n", ft_toupper(45));
	return (0);
}*/
