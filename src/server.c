/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:38:15 by maax              #+#    #+#             */
/*   Updated: 2024/02/29 16:11:23 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	ft_print_str(char **str1)
{
	ft_putstr_fd(*str1, 1);
	free(*str1);
	*str1 = NULL;
}

void	ft_store_char(char **str1, char **str2, char c, pid_t *client_pid)
{
	(*str2)[0] = c;
	if ((*str2)[0] != '\0')
	{
		*str1 = ft_strjoin_and_free(*str1, *str2);
	}
	else
	{
		ft_print_str(str1);
		kill(*client_pid, SIGUSR1);
		*client_pid = 0;
	}
}

static void	ft_handle_signal(int signal, siginfo_t *info, void *context)
{
	static char		c;
	static int		cursor;
	static pid_t	client_pid;
	static char		*str1;
	char			*str2;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	if (!str1)
		str1 = ft_strdup("");
	if (!c)
		c = 0;
	if (!cursor)
		cursor = 0;
	ft_putstr_fd("OK\n", 1);
	if (signal == SIGUSR2)
		c |= (1 << cursor);
	if (cursor == 15)
	{
		str2 = ft_strdup("0");
		ft_store_char(&str1, &str2, c, &client_pid);
		cursor = 0;
		c = 0;
		free(str2);
		return ;
	}
	cursor++;
	kill(client_pid, SIGUSR2);
}

int main(void)
{
    int 				pid;
	struct sigaction	s_sigaction;

    pid = getpid();
    ft_printf("pid = %d\n", pid);
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
