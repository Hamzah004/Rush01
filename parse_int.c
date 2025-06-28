/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabu-sha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:15:25 by yabu-sha          #+#    #+#             */
/*   Updated: 2025/06/28 15:32:51 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

int	parse_string(char *str, int *cluse)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && j < 16)
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			cluse[j] = str[i] - '0';
			j++;
		}
		else if (str[i] != ' ')
		{
			return (0);
		}
		i++;
	}
	if (j != 16)
	{
		return (0);
	}
	return (1);
}
