/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:38:15 by maax              #+#    #+#             */
/*   Updated: 2024/02/29 15:34:58 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	ft_send_end_str(int pid_server, char end)
{
	int	cursor;

	cursor = 0;
	while (cursor <= 15)
	{
		if ((end >> cursor) & 1)
			kill(pid_server, SIGUSR2);
		else
			kill(pid_server, SIGUSR1);
		cursor++;
		usleep(1000);
	}
}

void	ft_send_bit(int pid_server, char *str)
{
	int	cursor;
	int	i;
	int	len;
	
	i = 0;
    len = ft_strlen(str);
	while (i < len)
	{
		cursor = 0;
		while (cursor <= 15)
		{
			if ((str[i] >> cursor) & 1)
				kill(pid_server, SIGUSR2);
			else
				kill(pid_server, SIGUSR1);
			cursor++;
			usleep(10000);
		}
		i++;
	}
	ft_send_end_str(pid_server, '\0');
}

static void	ft_handle_signal(int signal)
{
	if (signal == SIGUSR1)
		ft_putstr_fd("Str received\n", 1);
	exit(1);
}

int main(int argc, char **argv)
{
	int					pid_server;
	char				*str;
	struct sigaction	s_sigaction;

	if (argc != 3)
	{
		ft_printf("Error, wrong number of params.\n");
		return (1);
	}
	pid_server = ft_atoi(argv[1]);
	str = argv[2];
	ft_memset(&s_sigaction, 0, sizeof(struct sigaction));
	s_sigaction.sa_handler = ft_handle_signal;
	sigaction(SIGUSR1, &s_sigaction, 0);
	ft_send_bit(pid_server, str);
	while(1)
	{
		pause();
	}
	return (0);
}
