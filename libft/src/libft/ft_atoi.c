/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:06:03 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:54:06 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_atoi : converts the initial portion of the string pointed to by nptr to
int.
Return value : converted value.*/

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	digit;

	sign = 1;
	digit = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == 43 || *nptr == 45)
	{
		if (*nptr == 45)
			sign *= -1;
		nptr++;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		digit = (digit * 10) + *nptr - 48;
		nptr++;
	}
	return (digit * sign);
}

/*#include <stdio.h>

int	main(void)
{
	printf("| ft_atoi |\n");
	printf("-12345 == %d\n", ft_atoi("\f \r-12345abc"));
	printf("789 == %d\n", ft_atoi("+789abc12"));
	printf("0 == %d\n", ft_atoi("\f \r+abc"));
	printf("%d\n", ft_atoi("ab"));
}*/
