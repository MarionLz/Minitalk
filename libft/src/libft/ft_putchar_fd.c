/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maax <maax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:48:41 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/31 11:21:32 by maax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_putchar : outputs the character ’c’ to the given file descriptor.*/

void	ft_putchar_fd(char c, int fd)
{
	int	res;

	res = write(fd, &c, 1);
	if (res == -1)
		return ;
}

/*#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	printf("| ft_putchar_fd |");
	
	int	fd;

	fd = open("test_fd.txt", O_RDWR | O_TRUNC);
	if (fd == -1)
		printf("open failed !\n");
	ft_putchar_fd('A', fd);
	if (close (fd) == -1)
		printf("close failed\n");
	return (0);
}*/