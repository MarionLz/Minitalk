/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maax <maax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:38:15 by maax              #+#    #+#             */
/*   Updated: 2024/03/04 15:37:44 by maax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

char	*str;

void	ft_send_end_str(int pid_server, char end)
{
	static int	cursor;

	if (cursor <= 15)
	{
		if ((end >> cursor) & 1)
			kill(pid_server, SIGUSR2);
		else
			kill(pid_server, SIGUSR1);
		cursor++;
	}
}

void	ft_send_bit(int pid_server)
{
	static int	cursor;
	static int	i;
	static int	len;

	if (!len)
		len = ft_strlen(str);
	if (i < len)
	{
		if (cursor <= 15)
		{
			if ((str[i] >> cursor) & 1)
				kill(pid_server, SIGUSR2);
			else
				kill(pid_server, SIGUSR1);
			cursor++;
		}
		if (cursor == 16)
		{
			i++;
			cursor = 0;
		}
	}
	else if (i == len)
		ft_send_end_str(pid_server, '\0');
}

static void	ft_handle_signal(int signal, siginfo_t *info, void *context)
{
	(void)context;
	if (signal == SIGUSR1)
	{
		ft_putstr_fd("Str received\n", 1);
		exit(1);
	}
	if (signal == SIGUSR2)
		ft_send_bit(info->si_pid);
}

int main(int argc, char **argv)
{
	int					pid_server;
	struct sigaction	s_sigaction;

	if (argc != 3)
	{
		ft_printf("Error, wrong number of params.\n");
		return (1);
	}
	pid_server = ft_atoi(argv[1]);
	str = argv[2];
	ft_send_bit(pid_server);
	ft_memset(&s_sigaction, 0, sizeof(struct sigaction));
	s_sigaction.sa_sigaction = ft_handle_signal;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while(1)
	{
		pause();
	}
	return (0);
}
