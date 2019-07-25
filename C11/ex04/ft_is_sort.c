/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 16:53:29 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/22 20:01:11 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int c;
	int d;

	i = 0;
	c = 0;
	d = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) < 0)
			c = 1;
		if ((*f)(tab[i], tab[i + 1]) > 0)
			d = 1;
		i++;
	}
	if (c == 1 && d == 1)
		return (0);
	return (1);
}
