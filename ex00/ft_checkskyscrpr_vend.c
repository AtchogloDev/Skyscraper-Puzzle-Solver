/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkskyscrpr_vend.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katchogl <katchogl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:40:35 by katchogl          #+#    #+#             */
/*   Updated: 2022/08/18 21:40:35 by katchogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		**ft_prepparams(int **skyscraper_params);
int		**ft_initparams(int *mes, int *views, int *pos, int **skyscrpr_params);
void	ft_updateargs(int *argsv, int **map, int *coordn);

void	ft_setvars2(int *argsv, int *coordn, int view_idx)
{
	argsv[0] = 0;
	argsv[1] = 0;
	if (view_idx >= 4 && view_idx < 8)
	{
		coordn[0] = 4;
		coordn[1] = view_idx - 4;
	}
	else if (view_idx >= 12 && view_idx < 16)
	{
		coordn[0] = view_idx - 12;
		coordn[1] = 4;
	}
}

int	ft_checkskyscrpr_vend(int **map, int *mes, int *views)
{
	int	view_idx;
	int	argsv[2];
	int	coordn[2];

	view_idx = 3;
	while (++view_idx < 16)
	{
		if (view_idx >= 8 && view_idx < 12)
			continue ;
		ft_setvars2 (argsv, coordn, view_idx);
		while ((view_idx >= 4 && view_idx < 8 && --coordn[0] >= 0)
			|| (view_idx >= 12 && view_idx < 16 && --coordn[1] >= 0))
			if (map[coordn[0]][coordn[1]] > argsv[0])
				ft_updateargs (argsv, map, coordn);
		if (argsv[1] != views[view_idx])
			return (-1);
	}
	return (0);
}
