/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 16:41:16 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/07 16:56:28 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_char_is_uppercase(char c)
{
	if (c >= 'A' & c <= 'Z')
		return (1);
	return (0);
}

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_char_is_uppercase(str[i]) == 1)
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
