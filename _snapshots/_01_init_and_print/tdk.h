/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdk.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecastan <hecastan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:26:44 by hecastan          #+#    #+#             */
/*   Updated: 2023/03/12 10:17:20 by hecastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TDK_H
# define TDK_H

#include <unistd.h>

typedef struct s_pov
{
	char	up[4];
	char	down[4];
	char	left[4];
	char	right[4];	
}
t_pov;

int	ft_error(void);
int	ft_parser(char *argv, t_pov *pov);
int	ft_init_grid(char grid[4][4]);
int	ft_solve(char grid[4][4], t_pov *pov);
int	ft_print_grid(char grid[4][4]);

#endif