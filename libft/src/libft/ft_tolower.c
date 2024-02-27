/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:39:05 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:52:33 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_tolower : if c is an uppercase letter, tolower() returns its lowercase
equivalent, if an lowercase representation exists in the current locale.
Return value : the converted letter or c if the conversion is not possible.*/

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c = c + 32;
	return (c);
}

/*#include <stdio.h>

int	main(void)
{
	printf("| ft_tolower |\n");
	printf("122 == %d\n", ft_tolower(90));
	printf("102 == %d\n", ft_tolower(70));
	printf("16 == %d\n", ft_tolower(16));
	return (0);
}*/
