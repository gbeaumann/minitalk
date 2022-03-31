/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:01:08 by gbeauman          #+#    #+#             */
/*   Updated: 2022/03/31 13:41:37 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minitalk.h"

void	check_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (pid[i] < 48 || pid[i] > 57)
		{
			ft_putstr("Error, invalid PID");
			exit(0);
		}
		else
			i++;
	}
}

void	send_char(char c, pid_t pid)
{
	int i;

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

int	main(int argc, char **argv)
{
	pid_t	pid;
	
	if (argc != 3)
	{
		ft_putstr("Error, invalid number of arguments\n");
		exit(0);
	}
	check_pid(argv[1]);
	pid = ft_atoi(argv[1]);
	send_message(argv[2], pid);
	return (0);
}
