/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecastan <hecastan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:17:14 by hecastan          #+#    #+#             */
/*   Updated: 2023/03/12 22:26:37 by hecastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tdk.h"

int	main (int argc, char **argv)
{
	t_pov	pov;
	char	grid[4][4];
	int		i;
	int		j;

	if (argc != 2)
		return (ft_error());
	if (ft_parser(argv[1], &pov) != 0)
		return (ft_error());
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			grid[i][j] = 0;
	}
	if (ft_solve(grid, &pov) != 0)
		return (ft_error());
	ft_print_grid(grid);
	return (SUCCESS);
}
