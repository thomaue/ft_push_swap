/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:21:41 by tauer             #+#    #+#             */
/*   Updated: 2024/02/09 16:55:53 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void correct_prev(element *first)
{
	element *current = NULL;

	current = first;
	while (current)
	{
		if (current->index == 0)
			current->prev = NULL;
		if (current->next)
			current->next->prev = current;
		current = current->next;
	}
}

void correct_index(element *first)
{
	element *current;
	unsigned long index;

	index = 0;
	current = first;
	while (current)
	{
		current->index = index;
		index++;
		current = current->next;
	}
}

void sorted_index(element *first)
{
	element *current;

	if (!first)
		return;
	current = first;
	while (current)
	{
		current->sorted_index = list_size(first) - (sort_check(first, current) + 1);
		current = current->next;
	}
}
