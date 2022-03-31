/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:29:09 by gbeauman          #+#    #+#             */
/*   Updated: 2022/03/31 15:09:17 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minitalk.h"

void	get_message(int signal)
{
	static char	c = 0;
	static int	i = 0;

	if (signal == SIGUSR1)
		c = c | 1 << i;
	i++;
	if (i == 8)
	{
		if (c == '\0')
			ft_putchar('\n');
		else
			ft_putchar(c);
		i = 0;
		c = 0;
	}
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
