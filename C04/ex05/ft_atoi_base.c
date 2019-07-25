/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 12:37:43 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/16 20:14:55 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_checkbase(char c, char *str, int *pos)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (str[i])
	{
		if ((str[i] < '0' || (str[i] > '9' && str[i] < 'A') ||
			(str[i] > 'Z' && str[i] < 'a') || str[i] > 'z'))
			return (0);
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		if (str[i] == c)
			*pos = i;
		i++;
		j = i + 1;
	}
	if (*pos == -1)
		return (0);
	return (1);
}

char	*ft_is_nbr(char *str, char *base, int *sign)
{
	int s;
	int pos[1];

	s = 1;
	*pos = -1;
	while (*str == ' ' || *str == '\v' ||
			*str == '\n' || *str == '\t' ||
			*str == '\f' || *str == '\r')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s *= -1;
		str++;
	}
	*sign = s;
	if (ft_checkbase(*str, base, pos) == 1)
		return (str);
	return (0);
}

int		ft_base_to_int(char *str, char *base)
{
	int i;
	int len_base;
	int result;
	int pos[1];

	i = 0;
	len_base = ft_strlen(base);
	result = 0;
	*pos = -1;
	while (ft_checkbase(str[i], base, pos))
	{
		result = result * len_base + *pos;
		*pos = -1;
		i++;
	}
	return (result);
}

int		ft_atoi_base(char *str, char *base)
{
	int result;
	int sign;

	result = 0;
	sign = 1;
	if (ft_is_nbr(str, base, &sign) && ft_strlen(base) > 1)
		result = ft_base_to_int(ft_is_nbr(str, base, &sign), base);
	else
		return (0);
	return (result * sign);
}
