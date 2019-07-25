/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:29:54 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/19 16:32:31 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_lenttab_sep(int size, char **strs, char *sep)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (i < size && strs[i])
	{
		if (strs[i + 1] && i + 1 < size)
			len += ft_strlen(sep) + ft_strlen(strs[i]);
		else
			len += ft_strlen(strs[i]);
		i++;
	}
	return (len);
}

int		ft_cat(char *str1, char *str2, int len_str2)
{
	int i;

	i = 0;
	while (str1[i])
	{
		str2[len_str2 + i] = str1[i];
		i++;
	}
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		j;
	int		len_str;

	i = 0;
	j = 0;
	len_str = ft_lenttab_sep(size, strs, sep);
	if (!(str = malloc(sizeof(char) * (len_str + 1))))
		return (0);
	if (size == 0)
		return (str);
	len_str = 0;
	while (i < size && strs[i])
	{
		len_str += ft_cat(strs[i], str, len_str);
		i++;
		if (i < size && strs[i])
			len_str += ft_cat(sep, str, len_str);
	}
	str[len_str] = '\0';
	return (str);
}
