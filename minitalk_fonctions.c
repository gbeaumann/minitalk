/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_fonctions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:30:20 by gbeauman          #+#    #+#             */
/*   Updated: 2022/04/08 09:43:55 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minitalk.h"

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

static int	count(unsigned int n)
{
	if (n > 9)
		return (count(n / 10) + 1);
	return (1);
}

static void	itoa_putnbr(char *str, unsigned int n)
{
	*str = n % 10 + 48;
	if (n > 9)
		itoa_putnbr(--str, n / 10);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				i;
	unsigned int	nb;

	if (n < 0)
	{
		nb = -n;
		i = count(nb);
		i++;
	}
	else
	{
		nb = n;
		i = count(nb);
	}
	str = malloc(i * sizeof(char) + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	itoa_putnbr(&str[i - 1], nb);
	if (n < 0)
		str[0] = '-';
	return (str);
}
