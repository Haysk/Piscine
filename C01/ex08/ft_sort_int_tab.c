/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:24:39 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/05 16:32:11 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;

	i = size;
	j = 0;
	while (i - 1 > 0)
	{
		i--;
		while (j < i)
		{
			if (tab[j + 1] < tab[j])
			{
				ft_swap(&tab[j + 1], &tab[j]);
			}
			j++;
		}
		j = 0;
	}
}
