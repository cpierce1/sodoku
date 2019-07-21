/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 15:28:45 by cpierce           #+#    #+#             */
/*   Updated: 2019/07/20 21:47:58 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

/*Remove or format comments before submitting to conform to norminette.*/
/*Empty spaces are set to -1*/

/*s_create should only be run if check_valid is run and returns 1*/
int	**s_create(char **argv)
{
	int **res;
	int x;
	int y;

	res = (int **)malloc(9 * 9 * sizeof(int *) + 1);
	y = 0;
	while (y < 9)
	{
		x = 0;
		res[y] = (int *)malloc(sizeof(int) * 9 + 1);
		while (x < 9)
		{
			if (argv[y + 1][x] == '.')
				res[y][x] = -1;
			else
				res[y][x] = argv[y + 1][x] - 48;
			x++;
		}
		y++;
	}
	return (res);
}

int	check_valid(char **grid)
{
	int x;
	int y;

	y = 1;
	while (y < 10)
	{
		x = 0;
		while (x < 9)
		{
			if (grid[y][x] > 57 || grid[y][x] <= 48 || grid[y][x] != '.' || grid[y][x] == '\0')
			{
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

void s_print(int **grid)
{
	int x;
	int y;
	
	y = 0;
	while (y < 9)
	{
		x = 0;
		while (x < 9)
		{
			char c = grid[x][y] + 48 /*Account for -1 spaces*/;
			write(1, &c, 1);
			write(1, " ", 1); /*Account for extra space at the end of each line later*/
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

int	main(int argc, char **argv)
{
	int **grid;

	if (argc != 10)
	{
		write(1, "Error\n\0", 6);
		return (0);
	}
	else if (check_valid(argv))
	{
		grid = s_create(argv);
		s_print(grid);
	}
	else
		write(1, "Error\n\0", 6);
}
