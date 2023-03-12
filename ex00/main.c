/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecastan <hecastan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:17:14 by hecastan          #+#    #+#             */
/*   Updated: 2023/03/12 20:18:03 by hecastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tdk.h"

int	main (int argc, char **argv)
{
	t_pov		pov;
	char		grid[4][4];

	if (argc != 2)
		return (ft_error());
	if (ft_parser(argv[1], &pov) != 0)
		return (ft_error());
	ft_init_grid(grid);
	if (ft_solve(grid, &pov) != 0)
		return (ft_error());
	ft_print_grid(grid);
	return (SUCCESS);
}
