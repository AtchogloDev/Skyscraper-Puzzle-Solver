/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdistinct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katchogl <katchogl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:39:25 by katchogl          #+#    #+#             */
/*   Updated: 2022/08/18 21:39:25 by katchogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_checkdistinct(int **map, int *pos, int skyscrpr)
{
	int	x;

	x = -1;
	while (++x < pos[0])
		if (map[x][pos[1]] == skyscrpr)
			return (-1);
	x = -1;
	while (++x < pos[1])
		if (map[pos[0]][x] == skyscrpr)
			return (-2);
	return (0);
}
