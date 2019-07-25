/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 18:59:03 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/20 22:47:12 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_charinstr(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int		ft_nbrword(char *str, char *charset)
{
	int	i;
	int	nb_word;

	i = 0;
	nb_word = 0;
	while (str[i])
	{
		if (!ft_charinstr(str[i], charset) &&
			(ft_charinstr(str[i + 1], charset) || !str[i + 1]))
			nb_word++;
		i++;
	}
	return (nb_word);
}

int		ft_strlen(char *str, char *charset)
{
	int i;

	i = 0;
	while (str[i] && !ft_charinstr(str[i], charset))
		i++;
	return (i);
}

char	*ft_strdup(char **src, char *charset)
{
	int		i;
	char	*cpy;

	i = 0;
	if (!(cpy = malloc(sizeof(char) * (ft_strlen(*src, charset) + 1))))
		return (0);
	while (**src && !ft_charinstr(**src, charset))
	{
		cpy[i] = **src;
		*src += 1;
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**tab;

	i = 0;
	if (!(tab = malloc(sizeof(char *) * (ft_nbrword(str, charset) + 1))))
		return (0);
	if (*str && !ft_charinstr(*str, charset))
	{
		tab[i] = ft_strdup(&str, charset);
		i++;
	}
	while (*str && ft_charinstr(*str, charset))
	{
		str++;
		if (*str && !ft_charinstr(*str, charset))
		{
			tab[i] = ft_strdup(&str, charset);
			i++;
		}
	}
	tab[i] = 0;
	return (tab);
}
