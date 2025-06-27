/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabu-sha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 20:12:31 by yabu-sha          #+#    #+#             */
/*   Updated: 2025/06/27 20:18:49 by yabu-sha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);


void	print_grid(int grid[][])
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while(col < 4)
		{
		
			ft_puthcar(grid[row][col] + '0');
		col++;
		}
		write(1,"\n",1);
		row++;
	}
}
