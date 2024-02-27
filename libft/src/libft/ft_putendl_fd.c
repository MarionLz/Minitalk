/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maax <maax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:24:40 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/31 11:26:32 by maax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_putendl_fd : outputs the string ’s’ to the given file descriptor
followed by a newline.*/

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		ft_putstr_fd(s, fd);
		ft_putchar_fd('\n', fd);
	}
}

/*#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	printf("| ft_putendl_fd |");
	
	int	fd;

	fd = open("test_fd.txt", O_RDWR | O_TRUNC);
	if (fd == -1)
		printf("open failed !\n");
	ft_putendl_fd("Hello World", fd);
	if (close (fd) == -1)
		printf("close failed\n");
	return (0);
}*/