/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:25:41 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:49:33 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_isdigit : checks for a digit (0 through 9).
Return value :
- nonzero if the character c falls into the tested class
- zero if not.*/

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

/*#include <stdio.h>

int	main(void)
{
	printf("| ft_isdigit |\n");
	printf("1 == %d\n", ft_isdigit(48));
	printf("1 == %d\n", ft_isdigit(53));
	printf("0 == %d\n", ft_isdigit(78));
	return (0);
}*/
