/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:36:13 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/13 13:57:21 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_dest;
	int				i;

	len_dest = ft_strlen(dest);
	i = 0;
	if (size <= (len_dest + ft_strlen(src)))
		return (ft_strlen(src) + size);
	while (src[i])
	{
		if (len_dest < size - 1)
			dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_dest + i);
}
