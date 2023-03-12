/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdk00.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecastan <hecastan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 08:36:37 by hecastan          #+#    #+#             */
/*   Updated: 2023/03/12 14:32:16 by hecastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tdk.h"

int	ft_error(void)
{
	write(1, "Error\n", 6);
	return (1);
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
			return (1);
		i++;
	}
	if (i != 31)
		return (1);
	str_ptr_pov[j] = '\0';
	j++;
	ft_putstr(str_ptr_pov);
	ft_putstr(pov->up);	
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
			grid[i][j] = '0';
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
			//grid[i][j] += '0';
			write(1, &grid[i][j], 1);
			//grid[i][j] -= '0';
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
