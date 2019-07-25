/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 18:55:17 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/04 19:19:23 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_pnbr(int nb, int i)
{
	if (nb > 9)
	{
		i = 1;
		ft_put_pnbr(nb / 10, i);
		ft_putchar(nb % 10 + '0');
	}
	else if (i == 0)
	{
		ft_putchar('0');
		ft_putchar(nb + '0');
	}
	else
		ft_putchar(nb + '0');
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	b = 1;
	while (a < 99)
	{
		while (b < 100)
		{
			ft_put_pnbr(a, 0);
			ft_putchar(' ');
			ft_put_pnbr(b, 0);
			if (a != 98)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			b++;
		}
		a++;
		b = a + 1;
	}
}
