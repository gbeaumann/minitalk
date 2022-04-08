/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:29:09 by gbeauman          #+#    #+#             */
/*   Updated: 2022/04/08 14:28:00 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minitalk.h"
#include	<stdio.h>

int	get_pid(int signal)
{
	static int	pid = 0;
	static int	i = 0;

	if (signal == SIGUSR1)
		pid = pid | 1 << i;
	i++;
	if (i == 32)
	{
		usleep(85);
		kill(pid, SIGUSR1);
		pid = 0;
		i = 0;
		return (0);
	}
	return (1);
}

int	print_message(int signal)
{
	static char	c = 0;
	static int	i = 0;

	if (signal == SIGUSR1)
		c = c | 1 << i;
	i++;
	if (i == 8)
	{
		if (c == '\0')
		{
			ft_putchar('\n');
			i = 0;
			c = 0;
			return (1);
		}
		else
			ft_putchar(c);
		i = 0;
		c = 0;
	}
	return (0);
}

void	get_message(int signal)
{
	static int	start = 0;

	if (start == 1)
	{
		start = get_pid(signal);
		if (start == 0)
			return ;
	}
	if (start == 0)
		start = print_message(signal);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr("Serveur PID: ");
	ft_putnbr(pid);
	write (1, "\n", 1);
	signal(SIGUSR1, get_message);
	signal(SIGUSR2, get_message);
	while (1)
		;
	return (0);
}
