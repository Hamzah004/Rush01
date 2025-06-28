/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabu-sha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 20:19:17 by yabu-sha          #+#    #+#             */
/*   Updated: 2025/06/28 17:08:21 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		parse_string(char *str, int *cluse);
int		solve(int grid[4][4], int cluse[], int pos);
void	print_grid(int grid[4][4]);
void	ft_putstr(char *str);
void	ft_putchar(char c);

void	fill_with_zeros1(int grid[4][4])
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
}

int	main(int argc, char *argv[])
{
	int	grid[4][4];
	int	cluse[16];

	fill_with_zeros1(grid);
	if (argc != 2 || !parse_string(argv[1], cluse))
	{
		ft_putstr("Error");
		write(1, "\n", 1);
		return (1);
	}
	if (!solve(grid, cluse, 0))
	{
		ft_putstr("Error");
		write(1, "\n", 1);
		return (1);
	}
	print_grid(grid);
	return (0);
}
