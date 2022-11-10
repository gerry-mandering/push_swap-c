/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_list_ab_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:55:26 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/10 18:36:03 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"

void	validate_list_ab(t_list *list_a, t_list *list_b)
{
	if (is_empty(list_b) && is_sorted(list_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
