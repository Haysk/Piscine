/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 23:10:51 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/15 20:01:18 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_puttab(char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			write(1, &tab[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
	if (!tab[0])
		write(1, "\n", 1);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if ((unsigned char)*s1 != (unsigned char)*s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ft_sort_params(char **tab)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 1;
	ptr = 0;
	while (tab[i])
	{
		while (tab[j])
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				ptr = tab[i];
				tab[i] = tab[j];
				tab[j] = ptr;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	ft_puttab(tab);
}

int		main(int ac, char *av[])
{
	if (ac > 1)
		ft_sort_params(&av[1]);
	return (0);
}
