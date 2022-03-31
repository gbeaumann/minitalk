/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_fonctions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:30:20 by gbeauman          #+#    #+#             */
/*   Updated: 2022/03/31 15:08:52 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minitalk.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write (1, "-2147483648", 11);
	else if (n >= 0 && n <= 9)
		ft_putchar(n + '0');
	else if (n < 0)
	{
		write (1, "-", 1);
		ft_putnbr(n * (-1));
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	resultat;
	int	np;

	i = 0;
	resultat = 0;
	np = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			np = -1;
		}
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		resultat = resultat * 10 + (str[i] - '0');
		i++;
	}
	return (resultat * np);
}
