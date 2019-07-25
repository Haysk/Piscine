/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 19:07:00 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/21 22:40:48 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	ft_addition(int a, int b)
{
	ft_putnbr(a + b);
}

void	ft_soustraction(int a, int b)
{
	ft_putnbr(a - b);
}

void	ft_multiplication(int a, int b)
{
	ft_putnbr(a * b);
}

void	ft_division(int a, int b)
{
	if (b == 0)
		write(1, "Stop : division by zero\n", 24);
	else
		ft_putnbr(a / b);
}

void	ft_modulo(int a, int b)
{
	if (b == 0)
		write(1, "Stop : modulo by zero\n", 22);
	else
		ft_putnbr(a % b);
}
