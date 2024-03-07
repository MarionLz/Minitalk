/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maax <maax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:38:15 by maax              #+#    #+#             */
/*   Updated: 2024/03/07 13:36:23 by maax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

char	*g_str;

void	send_end_str(int pid_server, char end)
{
	static int	cursor_end;

	if (cursor_end <= 7)
	{
		if ((end >> cursor_end) & 1)
			kill(pid_server, SIGUSR2);
		else
			kill(pid_server, SIGUSR1);
		cursor_end++;
	}
	else
		cursor_end = 0;
}

void	send_bit(int pid_server)
{
	static int			cursor_c;
	static unsigned int	i;

	if (i < ft_strlen(g_str))
	{
		if (cursor_c <= 7)
		{
			if ((g_str[i] >> cursor_c) & 1)
				kill(pid_server, SIGUSR2);
			else
				kill(pid_server, SIGUSR1);
			cursor_c++;
		}
		if (cursor_c == 8)
		{
			i++;
			cursor_c = 0;
		}
	}
	else
		send_end_str(pid_server, '\0');
}

static void	handle_signal(int signal, siginfo_t *info, void *context)
{
	(void)context;
	if (signal == SIGUSR1)
	{
		ft_putstr_fd("Str received\n", 1);
		exit(1);
	}
	if (signal == SIGUSR2)
	{
		send_bit(info->si_pid);
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
	g_str = argv[2];
	send_bit(pid_server);
	ft_memset(&s_sigaction, 0, sizeof(struct sigaction));
	s_sigaction.sa_sigaction = handle_signal;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while(1)
	{
		pause();
	}
	return (0);
}
