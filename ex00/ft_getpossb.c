/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpossb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katchogl <katchogl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 20:18:08 by katchogl          #+#    #+#             */
/*   Updated: 2022/08/18 20:18:08 by katchogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_checkdistinct(int **map, int *pos, int skyscrpr);
int		ft_checkpossb(int *mes, int *views, int *pos, int skyscrpr);
int		ft_checkskyscrpr_vstart(int **map, int *views, int *pos, int skyscrpr);
void	ft_getnextpos(int **map, int *mes, int *pos);

int	ft_getpossb(int **map, int *mes, int *views, int *possb)
{
	int	pos[2];
	int	idx;
	int	skyscrpr;

	ft_getnextpos (map, mes, pos);
	idx = -1;
	skyscrpr = 0;
	while (++skyscrpr <= 4)
		if (ft_checkdistinct (map, pos, skyscrpr) == 0)
			if (ft_checkpossb (mes, views, pos, skyscrpr) == 0)
				if (ft_checkskyscrpr_vstart (map, views, pos, skyscrpr) == 0)
					possb[++idx] = skyscrpr;
	return (idx + 1);
}
