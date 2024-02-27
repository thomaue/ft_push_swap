/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:38:46 by tauer             #+#    #+#             */
/*   Updated: 2024/02/19 11:55:28 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

unsigned int	last_on(unsigned int index)
{
	unsigned int	i;
	unsigned char	bit;

	i = 31;
	while (i--)
	{
		bit = (index >> i & 1) + '0';
		if ((bit & 1) == 1)
			return (i);
	}
	return (0);
}

unsigned long	biggest_bit(t_element *first)
{
	unsigned long	max_bit;
	t_element		*current;

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

int	is_last_little(t_element **first_a, t_element **first_b, t_element *current,
		unsigned long sorted_index)
{
	if (current->index == list_size(*first_a) - 1
		&& current->sorted_index == sorted_index)
	{
		rra(first_a);
		pb(first_b, first_a);
		return (1);
	}
	return (0);
}

void	push_lowest(t_element **first_a, t_element **first_b,
		unsigned long sorted_index)
{
	t_element		*current;
	unsigned long	min;
	unsigned long	index;

	current = (*first_a);
	min = current->sorted_index;
	index = 0;
	while (current)
	{
		if (current->sorted_index < min)
			min = current->sorted_index;
		if (is_last_little(first_a, first_b, current, sorted_index))
			return ;
		current = current->next;
	}
	while (index++ < list_size(*first_a))
	{
		if ((*first_a)->sorted_index == min)
		{
			pb(first_b, first_a);
			return ;
		}
		ra(first_a);
	}
}
