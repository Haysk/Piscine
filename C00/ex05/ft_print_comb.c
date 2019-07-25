/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:45:53 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/03 16:32:57 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_puchar(char c)
{
	write(1, &c, 1);
}

void	my_print(char c, char d, char u)
{
	ft_puchar(c);
	ft_puchar(d);
	ft_puchar(u);
	if (c != '7')
	{
		ft_puchar(',');
		ft_puchar(' ');
	}
}

void	ft_print_comb(void)
{
	char c;
	char d;
	char u;

	c = '0';
	d = '1';
	u = '2';
	while (c < d && c <= '7')
	{
		d = c + 1;
		while (d < u && d <= '8')
		{
			u = d + 1;
			while (u > d && u <= '9')
			{
				my_print(c, d, u);
				u++;
			}
			d++;
		}
		c++;
	}
}
