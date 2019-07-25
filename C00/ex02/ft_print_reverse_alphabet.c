/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:30:41 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/03 15:32:35 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	int		i;
	char	alph;

	i = 0;
	alph = 'z';
	while (i != 26)
	{
		write(1, &alph, 1);
		alph--;
		i++;
	}
}
