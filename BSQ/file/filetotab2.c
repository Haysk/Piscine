/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filetotab2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:42:06 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/24 16:51:39 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bsq.h"

int		ft_nbr_line(char *str, int len)
{
	int i;
	int nbr_line;

	i = len;
	nbr_line = 0;
	while (str[i + 1] && (str[i] == '\n' || str[i]))
	{
		nbr_line++;
		i += len + 1;
	}
	if (str[i - 1] != '\n' && str[i] == '\n')
		return (nbr_line + 1);
	return (0);
}

int		ft_checkstr(char *str, t_board_opt options)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == options.empty_case || str[i] == options.full_case
			|| str[i] == options.obstacle || str[i] == '\n'))
			return (0);
		i++;
	}
	return (1);
}
