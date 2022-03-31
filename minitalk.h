/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:47:52 by gbeauman          #+#    #+#             */
/*   Updated: 2022/03/31 13:37:01 by gbeauman         ###   ########.fr       */
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

#endif