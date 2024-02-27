/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maax <maax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 09:06:47 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/31 11:30:26 by maax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

int		ft_printf(const	char *format, ...);
void	my_ft_putchar(char c, int *len);
int		ft_convert_arg(char indic, va_list args, int *len);
void	my_ft_putstr(char *str, int *len);
void	my_ft_putnbr(int n, int *len);
void	my_ft_putnbr_p(unsigned long nbr, char *base, int *len);
void	my_ft_putnbr_unsigned(unsigned int n, int *len);
void	my_ft_putnbr_basehex(unsigned int nbr, char *base, int *len);

#endif