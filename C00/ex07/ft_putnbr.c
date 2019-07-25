/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 16:39:29 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/03 18:55:03 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_pnbr(unsigned int nb)
{
	if (nb > 9)
	{
		ft_put_pnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else
		ft_putchar(nb + '0');
}

void	ft_putnbr(int nb)
{
	unsigned int unsig_nb;

	unsig_nb = 0;
	if (nb < 0)
	{
		unsig_nb = nb * -1;
		ft_putchar('-');
		ft_put_pnbr(unsig_nb);
	}
	else
	{
		unsig_nb = nb;
		ft_put_pnbr(unsig_nb);
	}
}
