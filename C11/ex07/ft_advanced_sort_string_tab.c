/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 23:35:58 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/22 14:31:32 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		ft_tablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	char	*save;

	i = ft_tablen(tab) - 1;
	j = 0;
	while (i > j)
	{
		while (j < i)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
			{
				save = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = save;
			}
			j++;
		}
		j = 0;
		i--;
	}
}
