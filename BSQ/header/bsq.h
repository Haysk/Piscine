/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:23:23 by adylewsk          #+#    #+#             */
/*   Updated: 2019/07/24 23:06:07 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_board_opt
{
	int		nbr_line;
	int		len_line;
	char	empty_case;
	char	obstacle;
	char	full_case;
}				t_board_opt;

typedef	struct	s_case
{
	int		value;
	char	c;
}				t_case;

typedef	struct	s_sqr
{
	int		size;
	int		x;
	int		y;
}				t_sqr;

void			ft_putnbr(int nb);
void			ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_valuecmp(int left, int up, int diag);
int				ft_strlen(char *str);
int				ft_lenline(char *str);
int				ft_atoi(char *str);

int				ft_nbr_line(char *str, int len);
int				ft_checkstr(char *str, t_board_opt options);
t_case			**ft_freetab(t_case **tab, t_board_opt options);
char			*ft_file(char *av, int *len_file);
char			*ft_stdinfile(char *av, int *len_file);
char			*ft_setoption(char *buffer, t_board_opt *board_opt,
				int *len_file);
t_case			**ft_bufftotab(char *buffer, t_board_opt *options);
void			ft_valuetotab(t_case **tab, t_board_opt options, t_sqr *sqr);
void			ft_putsqr(t_sqr *sqr, char **buffer, t_board_opt options);

void			ft_printtab(t_case	**tab, t_board_opt options);
void			ft_printvaluetab(t_case	**tab, t_board_opt options);

#endif
