/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maax <maax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:11:46 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/31 11:23:28 by maax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*ft_putstr_fd : outputs the string ’s’ to the given file descriptor.*/

void	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	res;

	i = 0;
	while (s[i])
	{
		res = write(fd, &s[i], 1);
		if (res == -1)
			return ;
		i++;
	}
}

/*#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	printf("| ft_putstr_fd |\n");
	
	int	fd;

	fd = open("test_fd.txt", O_RDWR | O_TRUNC);
	if (fd == -1)
		printf("open failed !\n");
	ft_putstr_fd("Hello World", fd);
	if (close (fd) == -1)
		printf("close failed\n");
	return (0);
}*/