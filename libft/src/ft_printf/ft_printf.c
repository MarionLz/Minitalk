/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maax <maax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 09:06:42 by malauzie          #+#    #+#             */
/*   Updated: 2024/02/27 14:24:48 by maax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_is_null (char indic, va_list args, int *len)
{
	if (indic == 's' && !(va_arg(args, char *)))
	{
		len += write (1, "(null)", 6);
		return (1);
	}
	if (indic == 'p' && !(va_arg(args, char *)))
	{
		len += write (1, "(nill)", 6);
		return (1);
	}
	return (0);
}

int	ft_convert_arg(char indic, va_list args, int *len)
{
	if (indic == 'c')
		my_ft_putchar(va_arg(args, int), len);
	if (indic == 's')
		my_ft_putstr(va_arg(args, char *), len);
	if (indic == 'p')
	{
		len += write(1, "0x", 2);
		my_ft_putnbr_p(va_arg(args, unsigned long), "0123456789abcdef", len);
	}
	if (indic == 'd' || indic == 'i')
		my_ft_putnbr(va_arg(args, int), len);
	if (indic == 'u')
		my_ft_putnbr_unsigned(va_arg(args, unsigned int), len);
	if (indic == 'x')
		my_ft_putnbr_basehex(va_arg(args, unsigned int), "0123456789abcdef", len);
	if (indic == 'X')
		my_ft_putnbr_basehex(va_arg(args, unsigned int), "0123456789ABCDEF", len);
	if (indic == '%')
		my_ft_putchar('%', len);
	return (0);
}

int	ft_printf(const	char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
			my_ft_putchar(format[i], &len);
		else
		{
			i++;
			len += ft_convert_arg(format[i], args, &len);
		}
		i++;
	}
	va_end(args);
	return (len);
}

/*int	main(void)
{
	char	str1[7] = "coucou";

	printf("Return value = %d\n", printf("REAL (c):\nStr = abc%c\n", 'D'));
	printf("Return value = %d\n", ft_printf("MINE (c):\nStr = abc%c\n", 'D'));
	printf("\n");
	printf("Return value = %d\n", printf("REAL (s):\nStr = %s les gens\n", str1));
	printf("Return value = %d\n", ft_printf("MINE (s):\nStr = %s les gens\n", str1));
	printf("\n");
	char	str[5] = "allo";
	printf("%p\n", str);
	ft_printf("%p", str);
	return (0);
}*/
