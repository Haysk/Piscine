/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 16:27:22 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/21 16:52:15 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int i;
	int save;

	i = 0;
	save = 0;
	while (i < length)
	{
		if ((*f)(tab[i]) != 0)
			save++;
		i++;
	}
	return (save);
}
