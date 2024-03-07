/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maax <maax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:37:05 by malauzie          #+#    #+#             */
/*   Updated: 2024/03/07 13:28:51 by maax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	my_ft_putchar(char c, int *len)
{
	*len += write(1, &c, 1);
}

void	my_ft_putstr(char *str, int *len)
{
	int	i;

	i = 0;
	while (str[i])
	{
		*len += write(1, &str[i], 1);
		i++;
	}
}
