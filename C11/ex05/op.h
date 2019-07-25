/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 19:06:40 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/21 22:41:17 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# include <unistd.h>

int		ft_atoi(char *str);
void	ft_putnbr(int nb);
void	ft_addition(int a, int b);
void	ft_soustraction(int a, int b);
void	ft_multiplication(int a, int b);
void	ft_division(int a, int b);
void	ft_modulo(int a, int b);
#endif
