/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 21:03:18 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/22 20:49:30 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bsq.h"

char			*ft_is_nbr(char *str, int *sign)
{
	int i;

	i = 0;
	while (*str == ' ' || *str == '\v' ||
			*str == '\n' || *str == '\t' ||
			*str == '\f' || *str == '\r')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign *= -1;
		str++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i])
		return (0);
	return (str);
}

unsigned int	ft_str_to_int(char *str, unsigned int save)
{
	if (*str >= '0' && *str <= '9')
	{
		save += *str - 48;
		if (str[1] >= '0' && str[1] <= '9')
			save = ft_str_to_int(str + 1, save * 10);
	}
	return (save);
}

int				ft_atoi(char *str)
{
	int sign;

	sign = 1;
	if ((str = ft_is_nbr(str, &sign)))
		return (ft_str_to_int(str, 0) * sign);
	return (0);
}
