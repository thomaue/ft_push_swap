/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:38:46 by tauer             #+#    #+#             */
/*   Updated: 2024/02/13 18:31:00 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

unsigned int last_on(unsigned char index)
{
	unsigned int i;
	unsigned char bit;

	i = 8;
	while (i--)
	{
		bit = (index >> i & 1) + '0';
		if ((bit & 1) == 1)
			return (i);
	}
	return (0);
}

unsigned int biggest_bit(element *first)
{
	unsigned int max_bit;
	element *current;

	max_bit = 0;
	current = first;
	while (current)
	{
		if (last_on(current->sorted_index) > max_bit)
			max_bit = last_on(current->sorted_index);
		current = current->next;
	}
	return (max_bit);
}

int is_last_little(element **first_a, element **first_b, element *current, unsigned long sorted_index)
{
	if (current->index == list_size(*first_a) - 1 && current->sorted_index == sorted_index)
	{
		rra(first_a);
		pb(first_b, first_a);
		return (1);
	}
	return (0);
}

void push_lowest(element **first_a, element **first_b, unsigned long sorted_index)
{
	element *current;
	unsigned long min;
	unsigned long index;

	current = (*first_a);
	min = current->sorted_index;
	index = 0;
	// printf("[min : %ld]\n", min);
	while (current)
	{
		if (current->sorted_index < min)
			min = current->sorted_index;
		if (is_last_little(first_a, first_b, current, sorted_index))
			return;
		current = current->next;
	}
	while (index++ < list_size(*first_a))
	{
		if ((*first_a)->sorted_index == min)
		{
			pb(first_b, first_a);
			return;
		}
		ra(first_a);
	}
}
