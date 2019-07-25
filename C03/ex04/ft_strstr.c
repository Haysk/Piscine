/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:14:09 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/10 18:28:07 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;

	i = 0;
	while (*str && to_find[i])
	{
		if (str[i] == to_find[i])
			i++;
		else
		{
			i = 0;
			str++;
		}
	}
	if (!to_find[i])
		return (str);
	return (str = 0);
}
