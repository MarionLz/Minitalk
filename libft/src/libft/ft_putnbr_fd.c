/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:37:14 by malauzie          #+#    #+#             */
/*   Updated: 2024/02/29 16:17:50 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_putnbr_fd : outputs the integer ’n’ to the given file descriptor.*/

void	ft_putnbr_fd(int n, int fd)
{
	long	long_n;
	char	result;

	long_n = n;
	result = 0;
	if (long_n < 0)
	{
		long_n *= -1;
		ft_putchar_fd('-', fd);
	}
	if (long_n >= 10)
	{
		ft_putnbr_fd(long_n / 10, fd);
	}
	result = (result * 10) + long_n % 10 + 48;
	ft_putchar_fd(result, fd);
}

/*#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main (void)
{
	printf("| ft_putnbr_fd |");
	
	int	fd;

	fd = open("test_fd.txt", O_RDWR | O_TRUNC);
	if (fd == -1)
		printf("open failed !\n");
	ft_putnbr_fd(-2147483648, fd);
	if (close (fd) == -1)
		printf("close failed\n");
	return (0);
}*/