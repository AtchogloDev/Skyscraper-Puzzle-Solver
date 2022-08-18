/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katchogl <katchogl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 06:56:37 by katchogl          #+#    #+#             */
/*   Updated: 2022/08/14 06:56:37 by katchogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_split(char *str, int *arr)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		if (*str >= '1' && *str <= '4')
		{
			if (*(str + 1) == ' ' || *(str + 1) == '\0')
			{
				arr[count] = *str - '0';
				count++;
			}
			else
				return (-1);
		}
		else if (*str != ' ')
			return (-1);
		str++;
	}
	return (count);
}
