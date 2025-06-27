/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabu-sha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:10:53 by yabu-sha          #+#    #+#             */
/*   Updated: 2025/06/28 01:55:46 by yazen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	can_place(int grid[4][4], int row, int col, int num);
int	check_row_left(int grid[4][4], int row, int clues);
int     check_row_right(int grid[4][4], int row, int clues);
int     check_col_top(int grid[4][4], int col, int clues);
int     check_col_bot(int grid[4][4], int col, int clues);
int	is_valid(int grid[4][4], int cluse[]);

int	solve(int grid[4][4],int cluse[], int pos)
{
	int	row;
	int	col;
	int	num;

	row = pos / 4;
	col = pos % 4;
	num = 1;
	if(pos == 16)
		return(is_valid(grid,cluse));
	
	while(num <= 4)
	{
		if(can_place(grid,row,col,num))
		{
			grid[row][col] = num;
			int	valid = 1;

			if(col == 3)
				if(check_row_left(grid,row,cluse[8 + row] == 0)
				  ||check_row_right(grid,row,cluse[12 + row]) == 0)
					valid = 0;

			if(row == 3)
				if(check_col_top(grid,col,cluse[col] == 0)
				  ||check_col_bot(grid,col,cluse[col + 4]) == 0)
					valid = 0;
		
			if(valid && solve(grid,cluse,pos + 1))
				return (1);

		grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}
