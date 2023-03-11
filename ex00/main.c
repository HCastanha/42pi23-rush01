/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecastan <hecastan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:17:14 by hecastan          #+#    #+#             */
/*   Updated: 2023/03/11 15:44:40 by hecastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tdk.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	char		grid[4][4];
	int			i;
	int			j;
/*
**	Initializing the 4x4 grid with zeroes:
*/
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
/*
**	Printing the grid:
*/
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			write(1, &grid[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
