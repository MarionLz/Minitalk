/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maax <maax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:38:15 by maax              #+#    #+#             */
/*   Updated: 2024/03/07 13:36:13 by maax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	print_str(char **str1)
{
	ft_putstr_fd(*str1, 1);
	ft_putchar_fd('\n', 1);
	free(*str1);
	*str1 = NULL;
}

void	store_char(char **str1, char c, pid_t *client_pid)
{
	char	*str2;

	str2 = ft_strdup("0");
	str2[0] = c;
	if (str2[0] != '\0')
	{
		*str1 = ft_strjoin_and_free(*str1, str2);
		kill(*client_pid, SIGUSR2);
	}
	if (str2[0] == '\0')
	{
		print_str(str1);
		kill(*client_pid, SIGUSR1);
		*client_pid = 0;
	}
	free(str2);
}

static void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static char		c;
	static int		cursor_s;
	static pid_t	client_pid;
	static char		*str1;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	if (!str1)
		str1 = ft_strdup("");
	if (signal == SIGUSR2)
		c |= (1 << cursor_s);
	if (cursor_s < 7)
	{
		cursor_s++;
		kill(client_pid, SIGUSR2);
	}
	else
	{
		store_char(&str1, c, &client_pid);
		cursor_s = 0;
		c = 0;
		return ;
	}
}

int main(void)
{
	int 				pid;
	struct sigaction	s_sigaction;

	pid = getpid();
	ft_printf("pid = %d\n", pid);
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
