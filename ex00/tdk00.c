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

#include "tdk.h"

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
