/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabu-sha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:15:25 by yabu-sha          #+#    #+#             */
/*   Updated: 2025/06/27 17:40:00 by yabu-sha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>


void	ft_putchar(char c)
{
	write(1,&c,1);
}


void	ft_putstr(char *str)
{
	while(*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

int	parse_string(char *str , int *cluse) 
{
	//int	*c;
	int	i;
	int	j;

       	//c = (int *)malloc(16 * sizeof(int));
	i = 0;
	j = 0;
	while(str[i] && j < 16)
	{
		if(str[i] >= '1' && str[i] <= '4')
		{
			cluse[j] = str[i] - '0';
			j++;
		}
		else if(str[i] !=  ' ')
		{
		//	free(c);
			return 0;
		}
		i++;
	}
	if(j != 16)
	{                                  
	//	free(c);
		return 0;
	}

	return 1;

}
