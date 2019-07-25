/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 21:03:18 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/14 17:41:15 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char			*ft_is_nbr(char *str, int *sign)
{
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
	if (*str >= '0' && *str <= '9')
		return (str);
	return (0);
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
