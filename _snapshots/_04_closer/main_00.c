/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecastan <hecastan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:17:14 by hecastan          #+#    #+#             */
/*   Updated: 2023/03/12 20:27:34 by hecastan         ###   ########.fr       */
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdk00.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecastan <hecastan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 08:36:37 by hecastan          #+#    #+#             */
/*   Updated: 2023/03/12 20:18:46 by hecastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_error(void)
{
	write(1, "Error\n", 6);
	return (ERROR);
}

int	ft_parser(char *argv, t_pov *pov)
{
	int		i;
	int		j;
	char	*str_ptr_pov;

	i = 0;
	j = 0;
	str_ptr_pov = &pov->up[0];
	while (argv[i] != '\0')
	{
		if ((i % 2 != 0) && (argv[i] == ' '))
			i += 0;
		else if ((i % 2 == 0) && (argv[i] >= '1' && argv[i] <= '4'))
		{
			str_ptr_pov[j] = argv[i];
			j++;
		}
		else
			return (ERROR);
		i++;
	}
	if (i != 31)
		return (ERROR);
	str_ptr_pov[j] = '\0';
	ft_putstr(pov->up);
/*
** 	ft_putstr(str_ptr_pov);
*/
	return (SUCCESS);
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
			grid[i][j] = '0';
			j++;
		}
		i++;
	}
	return (SUCCESS);
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
			write(1, &grid[i][j], 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (SUCCESS);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
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
