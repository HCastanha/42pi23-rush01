/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdk.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecastan <hecastan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:26:44 by hecastan          #+#    #+#             */
/*   Updated: 2023/03/12 20:17:53 by hecastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TDK_H
# define TDK_H

# include <unistd.h>
# define SUCCESS 0
# define ERROR 1
typedef struct s_pov
{
	char	up[4];
	char	down[4];
	char	left[4];
	char	right[4];
}
t_pov;

int		ft_error(void);
int		ft_parser(char *argv, t_pov *pov);
int		ft_init_grid(char grid[4][4]);
int		ft_solve(char grid[4][4], t_pov *pov);
int		ft_print_grid(char grid[4][4]);
void	ft_putstr(char *str);
int		ft_scan_zero(char grid[4][4], int *x, int *y);
int		ft_is_n_valid(char grid[4][4], int x, int y, int n);
int		ft_is_row_valid(char grid[4][4], t_pov *pov, int x);
int		ft_is_col_valid(char grid[4][4], t_pov *pov, int y);

#endif