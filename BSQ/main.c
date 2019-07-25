/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:40:24 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/24 23:06:52 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/bsq.h"

int	ft_checkopt(t_board_opt options, char *buffer)
{
	if (!(options.empty_case || options.full_case || options.len_line
		|| options.nbr_line || options.obstacle) || buffer == 0)
		return (0);
	if (options.empty_case == options.full_case ||
		options.empty_case == options.obstacle ||
		options.full_case == options.obstacle)
		return (0);
	return (1);
}

int	bsq(char *av, char *(*file)(char *, int *))
{
	t_board_opt	options;
	t_case		**tab;
	t_sqr		sqr;
	char		*buffer;
	int			len_file;

	sqr.size = 0;
	len_file = -1;
	buffer = ft_setoption((file)(av, &len_file), &options, &len_file);
	if (ft_checkopt(options, buffer))
	{
		tab = ft_bufftotab(buffer, &options);
		if (tab && tab[0])
		{
			ft_valuetotab(tab, options, &sqr);
			ft_putsqr(&sqr, &buffer, options);
			tab = ft_freetab(tab, options);
			write(1, buffer, len_file - 1);
			ft_putchar('\n');
			return (1);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			if (!(bsq(av[i], ft_file)))
				ft_putstr("map error\n");
			if (av[i + 1])
				ft_putchar('\n');
			i++;
		}
	}
	else if (ac == 1)
		if (!(bsq(0, ft_stdinfile)))
			ft_putstr("map error\n");
	return (0);
}
