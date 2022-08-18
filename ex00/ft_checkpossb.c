/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkpossb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katchogl <katchogl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 12:15:35 by katchogl          #+#    #+#             */
/*   Updated: 2022/08/15 12:15:35 by katchogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		**ft_prepparams(int **skyscraper_params);
int		**ft_initparams(int *mes, int *views, int *pos, int **skyscrpr_params);
void	ft_free(int **arr, int m, int n);

int	ft_checkpossb(int *mes, int *views, int *pos, int skyscrpr)
{
	int	**params;
	int	i;
	int	max;

	params = ft_prepparams (params);
	ft_initparams (mes, views, pos, params);
	i = -1;
	while (++i < 4)
	{
		max = mes[0];
		if (i > 1)
			max = mes[1];
		if ((params[0][i] == 1 && params[1][i] == 0 && skyscrpr != max)
		|| (params[0][i] == 2 && params[1][i] == 0 && skyscrpr == max)
		|| (params[0][i] == 3 && ((params[1][i] == 0 && (skyscrpr == max
		|| skyscrpr == max - 1)) || (params[1][i] == 1 && skyscrpr == max)))
		|| (params[0][i] == 4 && skyscrpr != params[1][i] + 1))
			return (-1);
	}
	ft_free (params, 2, 4);
	return (0);
}

int	**ft_prepparams(int **skyscraper_params)
{
	int	*ptrs;
	int	i;

	ptrs = (int *) malloc (8 * 4);
	if (ptrs == NULL)
		return (NULL);
	skyscraper_params = (int **) malloc (2 * 8);
	if (skyscraper_params == NULL)
		return (NULL);
	i = 0;
	while (i < 2)
	{
		skyscraper_params[i] = ptrs + 4 * i;
		i++;
	}
	return (skyscraper_params);
}

int	**ft_initparams(int *mes, int *views, int *pos, int **skyscrpr_params)
{
	int	consts[2];
	int	i;

	i = -1;
	while (++i < 4)
	{
		consts[0] = pos[1];
		consts[1] = pos[0];
		if (i > 1)
		{
			consts[0] = pos[0];
			consts[1] = pos[1];
		}
		skyscrpr_params[0][i] = views[consts[0] + 4 * i];
		if (i == 0 || i == 2)
			skyscrpr_params[1][i] = consts[1];
		else
			if (i == 1)
				skyscrpr_params[1][i] = mes[1] - 1 - consts[1];
		else
				skyscrpr_params[1][i] = mes[0] - 1 - consts[1];
	}
	return (skyscrpr_params);
}
