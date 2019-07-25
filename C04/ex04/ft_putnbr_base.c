/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 20:46:35 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/14 17:44:00 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_checkbase(char *str)
{
	int i;
	int j;

	i = 0;
	j = 1;
	if (ft_strlen(str) < 2)
	{
		return (0);
	}
	while (str[i])
	{
		if ((str[i] < '0' || (str[i] > '9' && str[i] < 'A') ||
			(str[i] > 'Z' && str[i] < 'a') || str[i] > 'z'))
			return (0);
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

void	ft_int_to_base(unsigned int nbr, char *base, int min)
{
	unsigned int len_base;

	len_base = ft_strlen(base);
	if (nbr / len_base > len_base - 1)
		ft_int_to_base(nbr / len_base, base, 0);
	else if (nbr / len_base < len_base && nbr / len_base > 0)
		write(1, base + nbr / len_base + min, 1);
	write(1, base + nbr % len_base + min, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int min;

	min = 0;
	if (ft_checkbase(base))
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			if (nbr == -2147483648)
			{
				nbr += 1;
				min = 1;
			}
			ft_int_to_base(nbr * -1, base, min);
		}
		else
			ft_int_to_base(nbr, base, min);
	}
}
