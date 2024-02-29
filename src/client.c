/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:38:15 by maax              #+#    #+#             */
/*   Updated: 2024/02/29 16:25:01 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

char	*str;

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

void	ft_send_bit(int pid_server)
{
	static int	cursor;
	static int	i;
	static int	len;
	
	if (!i)
		i = 0;
	if (!cursor)
		cursor = 0;
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
		else
		{
			i++;
			cursor = 0;
		}
		ft_putnbr_fd(cursor, 1);
		ft_putchar_fd('\n', 1);
	}
	if (i == len)
	{
		ft_send_end_str(pid_server, '\0');
		i = 0;
	}
}

static void	ft_handle_signal(int signal, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signal == SIGUSR1)
	{
		ft_putstr_fd("Str received\n", 1);
		exit(1);
	}
	if (signal == SIGUSR2)
	{
		ft_putstr_fd("Bit received\n", 1);
		ft_send_bit(info->si_pid);
	}
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
	//ft_send_bit(pid_server);
	ft_memset(&s_sigaction, 0, sizeof(struct sigaction));
	s_sigaction.sa_sigaction = ft_handle_signal;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	ft_send_bit(pid_server);
	while(1)
	{
		pause();
	}
	return (0);
}
