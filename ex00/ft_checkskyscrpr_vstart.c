/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkskyscrpr_vstart.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katchogl <katchogl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:40:07 by katchogl          #+#    #+#             */
/*   Updated: 2022/08/18 21:40:07 by katchogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		**ft_prepparams(int **skyscraper_params);
int		**ft_initparams(int *mes, int *views, int *pos, int **skyscrpr_params);
void	ft_free(int **arr, int m, int n);

void	ft_setvars(int *argsv, int *coordn, int view_idx, int *pos)
{
	argsv[0] = 0;
	argsv[1] = 0;
	coordn[0] = pos[0];
	coordn[1] = pos[1];
	if (view_idx == 0)
		coordn[0] = -1;
	else if (view_idx == 2)
		coordn[1] = -1;
}

void	ft_updateargs(int *argsv, int **map, int *coordn)
{
	argsv[0] = map[coordn[0]][coordn[1]];
	argsv[1]++;
}

int	ft_checkskyscrpr_vstart(int **map, int *views, int *pos, int skyscrpr)
{
	int	consts[2];
	int	argsv[2];
	int	mes[2];
	int	**params;
	int	coordn[2];

	consts[0] = -1;
	params = ft_prepparams (params);
	ft_initparams (mes, views, pos, params);
	while (++consts[0] < 4)
	{
		if (consts[0] == 1 || consts[0] == 3)
			continue ;
		ft_setvars (argsv, coordn, consts[0], pos);
		while ((consts[0] == 0 && ++coordn[0] < pos[0])
			|| (consts[0] == 2 && ++coordn[1] < pos[1]))
			if (map[coordn[0]][coordn[1]] > argsv[0])
				ft_updateargs (argsv, map, coordn);
		if (skyscrpr > argsv[0] && argsv[1] >= params[0][consts[0]])
			return (-1);
	}
	ft_free (params, 2, 4);
	return (0);
}
