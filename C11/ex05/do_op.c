/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 19:34:32 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/21 22:39:35 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

int	main(int ac, char **av)
{
	void (*f[5])(int a, int b);

	f[0] = ft_addition;
	f[1] = ft_soustraction;
	f[2] = ft_division;
	f[3] = ft_multiplication;
	f[4] = ft_modulo;
	if (ac != 4)
		return (0);
	if (av[2][0] == '+' && av[2][1] == '\0')
		f[0](ft_atoi(av[1]), ft_atoi(av[3]));
	else if (av[2][0] == '-' && av[2][1] == '\0')
		f[1](ft_atoi(av[1]), ft_atoi(av[3]));
	else if (av[2][0] == '/' && av[2][1] == '\0')
		f[2](ft_atoi(av[1]), ft_atoi(av[3]));
	else if (av[2][0] == '*' && av[2][1] == '\0')
		f[3](ft_atoi(av[1]), ft_atoi(av[3]));
	else if (av[2][0] == 37 && av[2][1] == '\0')
		f[4](ft_atoi(av[1]), ft_atoi(av[3]));
	else
		write(1, "0\n", 2);
	return (0);
}
