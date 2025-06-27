/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabu-sha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:10:53 by yabu-sha          #+#    #+#             */
/*   Updated: 2025/06/27 20:10:31 by yabu-sha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	can_place(int grid[][], int row, int col, int num);
int	check_row_left(int grid[][], int row, int clues);
int     check_row_right(int grid[][], int row, int clues);
int     check_col_top(int grid[][], int col, int clues);
int     check_col_bot(int grid[][], int col, int clues);
int	is_valid(int grid[][], int cluse[]);

int	solve(int grid[][],int cluse[], int pos)
{
	int	row;
	int	col;
	int	valid;
	int	num;

	row = pos / 4;
	col = pos % 4;
	num = 1;
	valid = 1;
	if(pos == 16)
		return(is_valid(grid,clues));
	
	while(num <= 4)
	{
		if(can_place(grid,row,col,num))
		{
			grid[row][col] = num;
			
			if(col == 3)
				if(!(check_row_left(grid,row,clues) == 0
				  ||check_row_right(grid,row,clues) == 0))
					valid = 0;

			if(row == 3)
				if(!(check_col_top(grid,row,clues) == 0
				  ||check_col_bot(grid,row,clues) == 0))
					valid = 0;
		num++;
		}
		if(valid && solve(grid,cluse,pos + 1))
			return (1);

		grid[row][col] = 0;
	}
	return (0);
}
