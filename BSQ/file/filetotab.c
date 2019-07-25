/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filetotab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:58:03 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/24 22:39:48 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bsq.h"

t_case	**ft_freetab(t_case **tab, t_board_opt options)
{
	int i;

	i = 0;
	while (i <= options.nbr_line - 1)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (tab);
}

t_case	*ft_putcase(t_case *tab, char **buffer, t_board_opt options)
{
	int i;

	i = 0;
	while (**buffer != '\n' && **buffer)
	{
		tab[i].c = **buffer;
		tab[i].value = 0;
		i++;
		*buffer += 1;
	}
	return (tab);
}

t_case	**ft_bufftotab(char *buffer, t_board_opt *options)
{
	t_case	**tab;
	int		i;

	i = 0;
	options->len_line = ft_lenline(buffer);
	if (ft_nbr_line(buffer, options->len_line) != options->nbr_line)
		return (0);
	if (!ft_checkstr(buffer, *options))
		return (0);
	if (!(tab = malloc(sizeof(t_case) * (options->nbr_line))))
		return (0);
	while (*buffer && *buffer + 1 && i <= options->nbr_line)
	{
		tab[i] = malloc(sizeof(t_case) * (options->len_line));
		tab[i] = ft_putcase(tab[i], &buffer, *options);
		if (*buffer + 1)
			buffer++;
		i++;
	}
	return (tab);
}

char	*ft_setoption(char *buffer, t_board_opt *board_opt, int *len_file)
{
	int		i;
	char	*nbrline;

	i = 0;
	while (buffer && buffer[i] && buffer[i] != '\n')
		i++;
	board_opt->len_line = i;
	if (i >= 4)
	{
		*len_file -= i;
		board_opt->full_case = buffer[--i];
		board_opt->obstacle = buffer[--i];
		board_opt->empty_case = buffer[--i];
		nbrline = malloc(sizeof(char) * i);
		nbrline[i] = 0;
		while (--i >= 0)
			nbrline[i] = buffer[i];
		board_opt->nbr_line = ft_atoi(nbrline);
		free(nbrline);
		buffer += board_opt->len_line + 1;
	}
	if (board_opt->nbr_line > 0 && (buffer + board_opt->len_line + 1))
		return (buffer);
	return (0);
}

char	*ft_file(char *av, int *len_file)
{
	int		fd;
	int		buff;
	char	*buffer;

	buff = 1;
	if ((fd = open(av, 0)) == -1)
		return (0);
	if (!(buffer = malloc(sizeof(char) * 4096)))
		return (0);
	while (buff != 0)
	{
		buff = read(fd, buffer, sizeof(char) * 4096);
		*len_file += buff;
	}
	free(buffer);
	close(fd);
	if (!(buffer = malloc(sizeof(char) * *len_file + 1)))
		return (0);
	fd = open(av, 0);
	read(fd, buffer, sizeof(char) * *len_file + 1);
	buffer[*len_file + 1] = '\0';
	close(fd);
	return (buffer);
}
