/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 09:33:54 by gbeauman          #+#    #+#             */
/*   Updated: 2022/04/08 09:37:57 by gbeauman         ###   ########.fr       */
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

void	send_pid(int pid2, int pid)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		usleep(85);
		if (pid2 & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		pid2 = pid2 >> 1;
		i++;
	}
}
