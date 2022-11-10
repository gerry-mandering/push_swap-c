/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:36:39 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 20:00:27 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	insertion_sort(int *array, int size)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < size)
	{
		key = array[i];
		j = i - 1;
		while (j >= 0)
		{
			if (array[j] > key)
			{
				array[j + 1] = array[j];
				array[j] = key;
			}
			else
				break ;
			j--;
		}
		i++;
	}
}

void	sort_array(int *array, int size)
{
	insertion_sort(array, size);
}
