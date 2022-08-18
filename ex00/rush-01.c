/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katchogl <katchogl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 06:54:17 by katchogl          #+#    #+#             */
/*   Updated: 2022/08/14 06:54:17 by katchogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_split(char *str, int *arr);
int		**ft_initmap(int **map, int *mes);
int		ft_getpossb(int **map, int *mes, int *views, int *possb);
void	ft_printmap(int **map, int *mes);
void	ft_loop(int **map, int *mes, int *views, int *result);
int		ft_checkskyscrpr_vend(int **map, int *mes, int *views);
void	ft_free(int **arr, int m, int n);

int	main(int argc, char **argv)
{
	int	**map;
	int	mes[2];
	int	views[16];
	int	result;

	result = -1;
	if (argc - 1 == 1)
	{
		mes[0] = 4;
		mes[1] = 4;
		map = ft_initmap (map, mes);
		if (ft_split (argv[1], views) == 2 * (mes[0] + mes[1]) && map != NULL)
			ft_loop (map, mes, views, &result);
	}
	if (result < 0)
		write (1, "Error\n", 6);
	return (result);
}

void	ft_getnextpos(int **map, int *mes, int *pos)
{
	pos[0] = -1;
	while (++pos[0] < mes[0])
	{
		pos[1] = -1;
		while (++pos[1] < mes[1])
			if (map[pos[0]][pos[1]] == 0)
				return ;
	}
}

void	ft_refresh(int **map, int *mes, int *pos)
{
	int	i;
	int	j;

	i = pos[0] - 1;
	while (++i < mes[0])
	{
		j = pos[1];
		while (++j < mes[1])
			if (map[i][j] != 0)
				map[i][j] = 0;
	}
}

void	ft_printif_vend_are_fulfilled(int **map, int *mes
, int *views, int *result)
{
	if (ft_checkskyscrpr_vend (map, mes, views) != 0)
		return ;
	*result = 0;
	ft_printmap (map, mes);
	ft_free (map, mes[0], mes[1]);
}

void	ft_loop(int **map, int *mes, int *views, int *result)
{
	int	pos[2];
	int	possb[4];
	int	i;
	int	possb_count;

	if (*result == 0)
		return ;
	ft_getnextpos(map, mes, pos);
	possb_count = ft_getpossb (map, mes, views, possb);
	if (possb_count == 0)
		return ;
	i = -1;
	while (++i < possb_count)
	{
		map[pos[0]][pos[1]] = possb[i];
		if (pos[0] < mes[0] - 1 || pos[1] < mes[1] - 1)
		{
			ft_loop (map, mes, views, result);
			ft_refresh (map, mes, pos);
		}
	}
	if (pos[0] == mes[0] - 1 && pos[1] == mes[1] - 1)
		ft_printif_vend_are_fulfilled (map, mes, views, result);
}
