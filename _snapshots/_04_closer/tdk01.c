/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdk01.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecastan <hecastan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:01:26 by hecastan          #+#    #+#             */
/*   Updated: 2023/03/12 20:23:37 by hecastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tdk.h"

int	ft_solve(char grid[4][4], t_pov *pov)
{
	int		x;
	int		y;
	char	n;

	if (ft_scan_zero(grid, &x, &y) == 0)
	{
		ft_putstr("entrada na scan 0");
//		ft_putstr(&grid[x][y]);
		n = '0';
		while (n <= '4')
		{
			if (ft_is_n_valid(grid, x, y, n) == SUCCESS)
			{
				grid[x][y] = n;
				ft_putstr("entrada na scan 0");
				ft_putstr(&grid[x][y]);
				if (y == 3 && ft_is_row_valid(grid, pov, x) == 1)
					continue ;
				if (x == 3 && ft_is_col_valid(grid, pov, y) == 1)
					continue ;
				if (ft_solve(grid, pov) == 0)
					return (SUCCESS);
			}
			n++;
		}
		grid[x][y] = 0;
		ft_putstr(&grid[x][y]);
		return (ERROR);
	}
	return (SUCCESS);
}

int	ft_scan_zero(char grid[4][4], int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (grid[i][j] == 0)
			{
				*x = i;
				*y = j;
				return (ERROR);
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	ft_is_n_valid(char grid[4][4], int x, int y, int n)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[x][i] == n || grid[i][y] == n)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	ft_is_row_valid(char grid[4][4], t_pov *pov, int x)
{
	int	max_size;
	int	views;
	int	j;

	max_size = 0;
	views = 0;
	j = 0;
	while (j < 4)
	{
		if (grid[x][j] > max_size)
		{
			views++;
			max_size = grid[x][j];
		}
		j++;
	}
	if (views != pov->left[x])
		return (ERROR);
	max_size = 0;
	views = 0;
	while (j >= 0)
	{
		if (grid[x][j] > max_size)
		{
			views++;
			max_size = grid[x][j];
		}
		j--;
	}
	if (views != pov->right[x])
		return (ERROR);
	return (SUCCESS);
}

int	ft_is_col_valid(char grid[4][4], t_pov *pov, int y)
{
	int	max_size;
	int	views;
	int	i;

	max_size = 0;
	views = 0;
	i = 0;
	while (i < 4)
	{
		if (grid[i][y] > max_size)
		{
			views++;
			max_size = grid[i][y];
		}
		i++;
	}
	if (views != pov->left[y])
		return (ERROR);
	max_size = 0;
	views = 0;
	while (i >= 0)
	{
		if (grid[i][y] > max_size)
		{
			views++;
			max_size = grid[i][y];
		}
		i--;
	}
	if (views != pov->right[y])
		return (ERROR);
	return (SUCCESS);
}
