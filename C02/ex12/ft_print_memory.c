/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 19:48:36 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/09 22:41:37 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_int_to_base(unsigned long int nbr, char *base, int i)
{
	unsigned int len_base;

	len_base = ft_strlen(base);
	if (nbr / len_base > len_base - 1 || i > 0)
	{
		i--;
		ft_int_to_base(nbr / 16, base, i);
	}
	else if (nbr / len_base < len_base)
		write(1, base + nbr / len_base, 1);
	write(1, base + nbr % len_base, 1);
}

void	ft_printmem_hexa(unsigned char *addr, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < 16)
	{
		if (i % 2 != 1)
			write(1, " ", 1);
		if (i < size)
		{
			ft_int_to_base(addr[i], "0123456789abcdef", 0);
		}
		else
			write(1, "  ", 2);
		i++;
	}
	write(1, " ", 1);
}

void	ft_putmem_non_printable(char *str, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < 16)
	{
		if (i < size && !(str[i] > 31 && str[i] < 127))
			write(1, ".", 1);
		else if (i < size)
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int					pos_addr;
	int					size_int;
	unsigned long int	ptr_addr;

	pos_addr = size;
	size_int = (int)size;
	ptr_addr = (unsigned long int)addr;
	ptr_addr = ptr_addr << 28;
	ptr_addr = ptr_addr >> 28;
	while (size_int > 0)
	{
		ft_int_to_base((unsigned long int)ptr_addr, "0123456789abcdef", 13);
		write(1, ":", 1);
		ft_printmem_hexa((unsigned char *)&addr[pos_addr - size_int], size_int);
		ft_putmem_non_printable(&addr[pos_addr - size_int], size_int);
		ptr_addr += 16;
		size_int -= 16;
	}
	return (addr);
}
