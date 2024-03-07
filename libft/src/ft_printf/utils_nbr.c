/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maax <maax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:37:05 by malauzie          #+#    #+#             */
/*   Updated: 2024/03/07 13:28:41 by maax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	my_ft_putnbr_p(unsigned long nbr, char *base, int *len)
{
	int	base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (nbr / base_len > 0)
		my_ft_putnbr_p(nbr / base_len, base, len);
	*len += write(1, &base[nbr % base_len], 1);
}

void	my_ft_putnbr(int n, int *len)
{
	long	long_n;
	char	result;

	long_n = n;
	result = 0;
	if (long_n < 0)
	{
		long_n *= -1;
		*len += write(1, "-", 1);
	}
	if (long_n >= 10)
		my_ft_putnbr(long_n / 10, len);
	result = (result * 10) + long_n % 10 + 48;
	*len += write (1, &result, 1);
}

void	my_ft_putnbr_unsigned(unsigned int n, int *len)
{
	char	result;

	result = 0;
	if (n >= 10)
	{
		my_ft_putnbr_unsigned(n / 10, len);
	}
	result = (result * 10) + n % 10 + 48;
	*len += write (1, &result, 1);
}

void	my_ft_putnbr_basehex(unsigned int nbr, char *base, int *len)
{
	int		base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (nbr / base_len > 0)
		my_ft_putnbr_basehex(nbr / base_len, base, len);
	*len += write(1, &base[nbr % base_len], 1);
}
