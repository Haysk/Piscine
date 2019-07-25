/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_std.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:06:24 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/24 22:58:48 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bsq.h"

char	*ft_stdinfile(char *av, int *len_file)
{
	int		fd;
	int		buff;
	char	*buffer;

	buff = 0;
	if ((fd = open("mapstdin.txt", O_CREAT, 0666)) == -1)
		return (0);
	close(fd);
	if ((fd = open("mapstdin.txt", 2)) == -1)
		return (0);
	if (!(buffer = malloc(sizeof(char) * 4096)))
		return (0);
	while ((buff = read(0, buffer, sizeof(char) * 4096)) > 0)
	{
		*len_file += buff;
		write(fd, buffer, buff);
	}
	free(buffer);
	close(fd);
	fd = open("mapstdin.txt", 0);
	buffer = malloc(sizeof(char) * *len_file + 1);
	read(fd, buffer, sizeof(char) * *len_file + 1);
	buffer[*len_file + 1] = '\0';
	close(fd);
	return (buffer);
}
