/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:47:52 by gbeauman          #+#    #+#             */
/*   Updated: 2022/04/08 12:01:47 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include	<unistd.h>
# include	<signal.h>
# include	<stdio.h>
# include	<stdlib.h>
# include	<stdalign.h>
# include	<sys/types.h>

void	ft_putstr(char *str);
void	ft_putnbr(int n);
void	ft_putchar(char ch);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	check_pid(char *pid);
void	send_pid(int pid2, int pid);

#endif