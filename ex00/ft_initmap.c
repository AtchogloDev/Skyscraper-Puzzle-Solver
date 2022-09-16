/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katchogl <katchogl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 06:53:42 by katchogl          #+#    #+#             */
/*   Updated: 2022/08/14 06:53:42 by katchogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_emptymap(int **map, int *mes)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mes[0])
	{
		j = -1;
		while (++j < mes[1])
			map[i][j] = 0;
	}
	return (0);
}

int	**ft_initmap(int **map, int *mes)
{
	int	*ptrs;
	int	i;

	ptrs = (int *) malloc (2 * (mes[0] + mes[1]) * 4);
	map = (int **) malloc (mes[0] * 8);
	if (ptrs != NULL && map != NULL)
	{
		i = -1;
		while (++i < mes[0])
			map[i] = ptrs + mes[1] * i;
		if (ft_emptymap (map, mes) == 0)
			return (map);
	}
	free (ptrs);
	free (map);
	return (NULL);
}
