/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdk01.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecastan <hecastan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:01:26 by hecastan          #+#    #+#             */
/*   Updated: 2023/03/12 22:26:09 by hecastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tdk.h"

int	ft_solve(char grid[4][4], t_pov *pov)
{
	int		x;
	int		y;
	int		n;

	if (ft_scan_zero(grid, &x, &y) == FOUND)
	{
		n = '0';
		while (++n <= '4')
		{
			if (ft_is_n_valid(grid, x, y, n) == SUCCESS)
			{
				grid[x][y] = n;
				if (y == 3 && ft_is_row_valid(grid, pov, x, -1) == SUCCESS)
					continue ;
				if (x == 3 && ft_is_col_valid(grid, pov, y, -1) == SUCCESS)
					continue ;
				if (ft_solve(grid, pov) == SUCCESS)
					return (SUCCESS);
			}
		}
		grid[x][y] = 0;
		return (ERROR);
	}
	return (SUCCESS);
}

int	ft_scan_zero(char grid[4][4], int *x, int *y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (grid[i][j] == 0)
			{
				*x = i;
				*y = j;
				return (FOUND);
			}
		}
	}
	return (FINISHED);
}

int	ft_is_n_valid(char grid[4][4], int x, int y, int n)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (grid[x][i] == n || grid[i][y] == n)
			return (ERROR);
	return (SUCCESS);
}

int	ft_is_row_valid(char grid[4][4], t_pov *pov, int x, int j)
{
	int	max_height;
	int	views;

	max_height = 0;
	views = 0;
	while (++j < 4)
	{
		if (grid[x][j] > max_height)
			max_height = grid[x][j];
		views = views + (grid[x][j] > max_height);
	}
	if (views != pov->left[x])
		return (ERROR);
	max_height = 0;
	views = 0;
	while (--j >= 0)
	{
		if (grid[x][j] > max_height)
			max_height = grid[x][j];
		views = views + grid[x][j] > max_height;
	}
	if (views != pov->right[x])
		return (ERROR);
	return (SUCCESS);
}

int	ft_is_col_valid(char grid[4][4], t_pov *pov, int y, int i)
{
	int	max_height;
	int	views;

	max_height = 0;
	views = 0;
	while (++i < 4)
	{
		if (grid[i][y] > max_height)
			max_height = grid[i][y];
		views = views + grid[i][y] > max_height;
	}
	if (views != pov->left[y])
		return (ERROR);
	max_height = 0;
	views = 0;
	while (--i >= 0)
	{
		if (grid[i][y] > max_height)
			max_height = grid[i][y];
		views = views + grid[i][y] > max_height;
	}
	if (views != pov->right[y])
		return (ERROR);
	return (SUCCESS);
}
