/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:36:48 by tauer             #+#    #+#             */
/*   Updated: 2024/02/19 11:55:40 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	two_digit_sort(t_element **first)
{
	if ((*first)->sorted_index == 1)
		ra(first);
}

void	three_digit_sort(t_element **first)
{
	unsigned long	min;
	unsigned long	medium;
	unsigned long	big;

	min = get_min(*first);
	medium = get_medium(*first);
	big = get_max(*first);
	if (is_no_sorted(first))
		if (first_littlest(first, min, big))
			if (first_medium(first, medium, big))
				first_biggest(first, medium, big);
}

void	little_sort(t_element **first)
{
	if (!(*first))
		return ;
	else if (list_size((*first)) == 3)
		three_digit_sort(first);
	else
		two_digit_sort(first);
}

void	medium_sort(t_element **first_a, t_element **first_b)
{
	if (list_size(*first_a) == 5)
	{
		push_lowest(first_a, first_b, 0);
		push_lowest(first_a, first_b, 1);
		three_digit_sort(first_a);
		while ((*first_b))
			pa(first_a, first_b);
	}
	else
	{
		push_lowest(first_a, first_b, 0);
		three_digit_sort(first_a);
		while ((*first_b))
			pa(first_a, first_b);
	}
}

void	radix(t_element **first_a, t_element **first_b)
{
	unsigned int	max_bit;
	unsigned int	i_bit;
	unsigned int	size;
	unsigned int	index;

	max_bit = biggest_bit((*first_a));
	size = list_size((*first_a));
	i_bit = 0;
	while (i_bit <= max_bit)
	{
		index = 0;
		while (index < size)
		{
			if ((((*first_a)->sorted_index >> i_bit) & 1) == 0)
				pb(first_b, first_a);
			else
				ra(first_a);
			index++;
		}
		while ((*first_b))
			pa(first_a, first_b);
		i_bit++;
	}
}
