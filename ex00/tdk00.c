/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdk00.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecastan <hecastan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 08:36:37 by hecastan          #+#    #+#             */
/*   Updated: 2023/03/12 22:23:13 by hecastan         ###   ########.fr       */
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

	i = -1;
	j = -1;
	str_ptr_pov = &pov->up[0];
	while (argv[++i] != '\0')
	{
		if ((i % 2 != 0) && (argv[i] == ' '))
			continue ;
		if ((i % 2 != 0) && (argv[i] != ' '))
			return (ERROR);
		if ((i % 2 == 0) && (argv[i] < '1' || argv[i] > '4'))
			return (ERROR);
		str_ptr_pov[++j] = argv[i];
	}
	if (i != 31)
		return (ERROR);
	str_ptr_pov[j] = '\0';
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
			grid[i][j] = 0;
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

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			write(1, &grid[i][j], 1);
			if (j != 3)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
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
