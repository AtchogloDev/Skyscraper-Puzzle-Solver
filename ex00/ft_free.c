/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katchogl <katchogl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:14:11 by katchogl          #+#    #+#             */
/*   Updated: 2022/08/18 21:14:11 by katchogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_free(int **arr, int m, int n)
{
	int	coordn[2];

	coordn[0] = -1;
	while (++coordn[0] < m)
	{
		coordn[1] = -1;
		while (++coordn[1] < n)
			free (&arr[coordn[0]][coordn[1]]);
		free (arr[coordn[0]]);
	}
}
