/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 13:21:42 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/21 16:25:42 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *save;

	i = 0;
	if (!(save = malloc(sizeof(int) * length)))
		return (0);
	while (i < length)
	{
		save[i] = (*f)(tab[i]);
		i++;
	}
	return (save);
}
