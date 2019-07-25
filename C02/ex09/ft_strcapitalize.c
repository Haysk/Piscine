/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 16:56:20 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/08 19:13:59 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_alphnum(char c)
{
	if ((c >= 'a' && c <= 'z') ||
		(c >= '0' && c <= '9') ||
		(c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int		ft_char_is_uppercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int		ft_char_is_lowercase(char c)
{
	if (c >= 'a' && c <= 'z')
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

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 1;
	str = ft_strlowcase(str);
	if (ft_char_is_lowercase(str[0]))
		str[0] = str[0] - 32;
	while (str[i] != '\0')
	{
		if (ft_char_is_lowercase(str[i]) == 1 && ft_alphnum(str[i - 1]) == 0)
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
