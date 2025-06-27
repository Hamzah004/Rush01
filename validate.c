/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabu-sha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:45:39 by yabu-sha          #+#    #+#             */
/*   Updated: 2025/06/27 19:10:15 by yabu-sha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	can_place(int grid[4][4], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	check_row_left(int grid[4][4], int row, int clues)
{
	int	i;
	int	visible;
	int	max;
	
	i = 1;
	max = grid[row][0];
	visible	= 1;
	while (i < 4)
	{
		if (grid[row][i] > max)
		{
			visible++;
			max = grid[row][i];
		}
		i++;
	}
	return (visible == clues);
}

int     check_row_right(int grid[4][4], int row, int clues)
{       
        int     i;
        int     visible;
        int     max;

        i = 2;
        max = grid[row][3];
        visible = 1;
        while (i >= 0)
        {		//max < g
                if (grid[row][i] > max)
                {
                        visible++;
                        max = grid[row][i];
                }
                i--;
        }
        return (visible == clues);
}

int     check_col_top(int grid[4][4], int col, int clues)
{
        int     i;
        int     visible;
        int     max;

        i = 1;
        max = grid[0][col];
        visible = 1;
        while (i < 4)
        {            
                if (grid[i][col] > max)
                {
                        visible++;
                        max = grid[i][col];
                }
                i++;
        }
        return (visible == clues);
}


int     check_col_bot(int grid[4][4], int col, int clues)
{
        int     i;
        int     visible;
        int     max;

        i = 2;
        max = grid[3][col];
        visible = 1;
        while (i >= 0)
        {            
                if (grid[i][col] > max)
                {
                        visible++;
                        max = grid[i][col];
                }
                i--;
        }
        return (visible == clues);
}

int	is_valid(int grid[4][4], int cluse[])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if(!check_col_top(grid,i,cluse[i]))
			return (0);
		if(!check_col_bot(grid,i,cluse[i+4]))
			return (0);
		if(!check_row_left(grid,i,cluse[i+8]))
                        return (0);
		if(!check_row_right(grid,i,cluse[i+12]))
                        return (0);
		i++;
	}
	return (1);
}
