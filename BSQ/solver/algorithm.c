/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:00:49 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/24 14:02:11 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bsq.h"

void	ft_printtab(t_case **tab, t_board_opt options)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < options.nbr_line)
	{
		while (j < options.len_line)
		{
			ft_putchar(tab[i][j].c);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}

void	ft_printvaluetab(t_case **tab, t_board_opt options)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < options.nbr_line)
	{
		while (j < options.len_line)
		{
			ft_putnbr(tab[i][j].value);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}

void	ft_possqr(t_sqr *sqr, int value, int x, int y)
{
	sqr->size = value;
	sqr->x = x;
	sqr->y = y;
}

void	ft_putsqr(t_sqr *sqr, char **buffer, t_board_opt options)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	j = 0;
	x = sqr->x;
	y = sqr->y;
	while (i < sqr->size)
	{
		while (j < sqr->size)
		{
			buffer[0][y * (options.len_line + 1) + x] = options.full_case;
			j++;
			x--;
		}
		j = 0;
		i++;
		x = sqr->x;
		y--;
	}
}

void	ft_valuetotab(t_case **tab, t_board_opt options, t_sqr *sqr)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (y < options.nbr_line)
	{
		while (x < options.len_line)
		{
			if ((y == 0 || x == 0) && tab[y][x].c != options.obstacle)
				tab[y][x].value = 1;
			else if (tab[y][x].c != options.obstacle)
				tab[y][x].value = ft_valuecmp(tab[y][x - 1].value,
				tab[y - 1][x].value, tab[y - 1][x - 1].value);
			if (tab[y][x].value > sqr->size)
				ft_possqr(sqr, tab[y][x].value, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}
