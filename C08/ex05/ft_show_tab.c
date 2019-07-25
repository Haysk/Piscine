/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 18:53:43 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/20 16:59:12 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

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
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		ft_putnbr(par[i].size);
		ft_putstr(par[i].copy);
		i++;
	}
}
