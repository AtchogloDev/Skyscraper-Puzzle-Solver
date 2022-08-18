/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katchogl <katchogl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 06:59:08 by katchogl          #+#    #+#             */
/*   Updated: 2022/08/14 06:59:08 by katchogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printmap(int **map, int *mes)
{
	char	chr;
	int		i;
	int		j;

	i = -1;
	while (++i < mes[0])
	{
		j = -1;
		while (++j < mes[1])
		{
			chr = map[i][j] + '0';
			write (1, &chr, 1);
			if (j != mes[1] - 1)
				write (1, " ", 1);
		}
		write (1, "\n", 1);
	}
}
