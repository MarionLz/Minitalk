/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:24:19 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/17 10:49:45 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_itoa : allocates (malloc) and returns a string representing the integer
received as an argument. Negative numbers must be handled.
Return value : the string representing the integer or NULL if malloc fails.*/

static size_t	ft_count_digit(long long_n)
{
	unsigned int	count;

	count = 0;
	if (long_n < 0)
	{
		long_n *= -1;
		count++;
	}
	if (long_n == 0)
		count++;
	while (long_n > 0)
	{
		long_n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	long_n;
	int		size_n;
	char	*str_n;

	long_n = n;
	size_n = ft_count_digit(long_n);
	str_n = (char *)malloc(size_n * sizeof(char) + 1);
	if (!str_n)
		return (NULL);
	if (long_n < 0)
		long_n *= -1;
	str_n[size_n] = '\0';
	size_n--;
	while (size_n >= 0)
	{
		str_n[size_n] = long_n % 10 + 48;
		long_n = long_n / 10;
		size_n--;
	}
	if (n < 0)
		str_n[0] = '-';
	return (str_n);
}

/*#include <stdio.h>

int	main(void)
{
	printf("| ft_itoa |\n");

	char	*str_itoa;

	str_itoa = ft_itoa(-150);
	printf("-150 == %s\n", str_itoa);
	free (str_itoa);
	str_itoa = ft_itoa(-2147483648);
	printf("-2147483648 == %s\n", str_itoa);
	free (str_itoa);
	str_itoa = ft_itoa(0);
	printf("0 == %s\n", str_itoa);
	free (str_itoa);
	str_itoa = ft_itoa(24670);
	printf("24670 == %s\n", str_itoa);
	free (str_itoa);
}*/