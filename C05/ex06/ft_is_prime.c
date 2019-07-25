/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 13:04:25 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/16 20:04:02 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int prm;

	prm = 2;
	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	while (prm <= nb / prm)
	{
		if (nb % prm == 0)
			return (0);
		prm++;
	}
	return (1);
}