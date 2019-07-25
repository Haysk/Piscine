/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:37:15 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/13 17:21:29 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

int		main(int ac, char *av[])
{
	int i;

	(void)ac;
	i = 1;
	while (av[i])
	{
		ft_putstr(av[i]);
		i++;
	}
	return (0);
}
