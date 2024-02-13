/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_digits_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:51:11 by tauer             #+#    #+#             */
/*   Updated: 2024/02/13 18:31:30 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

unsigned long get_min(element *first)
{
	unsigned long min;

	min = 0;

	if ((first->sorted_index < first->next->sorted_index) && (first->sorted_index < first->next->next->sorted_index))
		min = first->sorted_index;
	else if ((first->next->sorted_index < first->sorted_index) && (first->next->sorted_index < first->next->next->sorted_index))
		min = first->next->sorted_index;
	else if ((first->next->next->sorted_index < first->sorted_index) && (first->next->next->sorted_index < first->next->sorted_index))
		min = first->next->next->sorted_index;
	return (min);
}
unsigned long get_medium(element *first)
{
	unsigned long medium;

	medium = 0;

	if ((first->sorted_index > first->next->sorted_index) && (first->sorted_index < first->next->next->sorted_index))
		medium = first->sorted_index;
	else if ((first->sorted_index < first->next->sorted_index) && (first->sorted_index > first->next->next->sorted_index))
		medium = first->sorted_index;
	else if ((first->next->sorted_index > first->sorted_index) && (first->next->sorted_index < first->next->next->sorted_index))
		medium = first->next->sorted_index;
	else if ((first->next->sorted_index < first->sorted_index) && (first->next->sorted_index > first->next->next->sorted_index))
		medium = first->next->sorted_index;
	else if ((first->next->next->sorted_index > first->sorted_index) && (first->next->next->sorted_index < first->next->sorted_index))
		medium = first->next->next->sorted_index;
	else if ((first->next->next->sorted_index < first->sorted_index) && (first->next->next->sorted_index > first->next->sorted_index))
		medium = first->next->next->sorted_index;
	return (medium);
}

unsigned long get_max(element *first)
{
	unsigned long max;

	max = 0;

	if ((first->sorted_index > first->next->sorted_index) && (first->sorted_index > first->next->next->sorted_index))
		max = first->sorted_index;
	else if ((first->next->sorted_index > first->sorted_index) && (first->next->sorted_index > first->next->next->sorted_index))
		max = first->next->sorted_index;
	else if ((first->next->next->sorted_index > first->sorted_index) && (first->next->next->sorted_index > first->next->sorted_index))
		max = first->next->next->sorted_index;
	return (max);
}