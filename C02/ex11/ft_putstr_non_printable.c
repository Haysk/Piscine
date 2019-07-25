/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 13:46:37 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/10 18:47:01 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_int_to_base(int nbr, char *base)
{
	int len_base;

	len_base = ft_strlen(base);
	if (nbr / len_base > len_base - 1)
		ft_int_to_base(nbr / len_base, base);
	else if (nbr / len_base < len_base)
		write(1, base + nbr / len_base, 1);
	write(1, base + nbr % len_base, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] > 31 && str[i] < 127))
		{
			write(1, "\\", 1);
			ft_int_to_base((unsigned char)str[i], "0123456789abcdef");
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
