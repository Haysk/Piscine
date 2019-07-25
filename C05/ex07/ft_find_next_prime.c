/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 18:13:37 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/15 21:57:29 by adylewsk         ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	if (nb < 0)
		return (2);
	while (ft_is_prime(nb) == 0 && nb < 2147483647)
		nb++;
	if (ft_is_prime(nb))
		return (nb);
	return (0);
}
