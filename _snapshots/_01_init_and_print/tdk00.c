/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdk00.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecastan <hecastan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 08:36:37 by hecastan          #+#    #+#             */
/*   Updated: 2023/03/12 10:24:15 by hecastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tdk.h"

int	ft_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int	ft_parser(char *argv, t_pov *pov)
{
	return (0);
}

int	ft_init_grid(char grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_solve(char grid[4][4], t_pov *pov)
{
	return (0);
}

int	ft_print_grid(char grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] += '0';
			write(1, &grid[i][j], 1);
			grid[i][j] -= '0';
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
