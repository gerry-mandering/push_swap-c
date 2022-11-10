/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:45:33 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 20:01:16 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_max2(int num_a, int num_b)
{
	if (num_a > num_b)
		return (num_a);
	else
		return (num_b);
}

int	get_min4(int *num_arr)
{
	int	i;
	int	size;
	int	min;

	i = 0;
	size = 4;
	while (i < size)
	{
		if ((i == 0) || (num_arr[i] < min))
			min = num_arr[i];
		i++;
	}
	return (min);
}

int	get_max_index(int *num_arr, int size)
{
	int	i;
	int	max;
	int	max_index;

	i = 0;
	while (i < size)
	{
		if ((i == 0) || (num_arr[i] > max))
		{
			max = num_arr[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

int	get_min_index(int *num_arr, int size)
{
	int	i;
	int	min;
	int	min_index;

	i = 0;
	while (i < size)
	{
		if ((i == 0) || (num_arr[i] < min))
		{
			min = num_arr[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}
