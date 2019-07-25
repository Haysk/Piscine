/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valuecmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 17:15:14 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/22 19:44:10 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bsq.h"

int		ft_valuecmp(int left, int up, int diag)
{
	if (left <= up && left <= diag)
		return (left + 1);
	if (up <= left && up <= diag)
		return (up + 1);
	return (diag + 1);
}
