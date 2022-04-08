/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:01:08 by gbeauman          #+#    #+#             */
/*   Updated: 2022/04/08 09:38:01 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minitalk.h"

void	send_char(char c, pid_t pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		usleep(85);
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c >> 1;
		i++;
	}
}

void	send_message(char *message, pid_t pid)
{
	int	i;

	i = 0;
	while (message[i])
	{
		send_char(message[i], pid);
		i++;
	}
	send_char('\0', pid);
}

void	get_confirmation(int signal)
{
	if (signal == SIGUSR1)
		write (1, "Message received", 16);
	exit (0);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	pid_t	pid2;

	pid2 = getpid();
	if (argc != 3)
	{
		ft_putstr("Error, invalid number of arguments\n");
		exit(0);
	}
	write (1, "\n", 1);
	check_pid(argv[1]);
	pid = ft_atoi(argv[1]);
	send_message(argv[2], pid);
	send_pid(pid2, pid);
	signal(SIGUSR1, get_confirmation);
	while (1)
		;
	return (0);
}
