/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_digits_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:27:41 by tauer             #+#    #+#             */
/*   Updated: 2024/02/13 18:18:45 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int first_littlest(element **first, unsigned long little, unsigned long big)
{
	if ((*first)->sorted_index == little)
	{
		if ((*first)->next->sorted_index == big)
		{
			rra(first);
			sa(first);
		}
		else
			sa(first);
		return (0);
	}
	return (1);
}

int first_medium(element **first, unsigned long medium, unsigned long big)
{
	if ((*first)->sorted_index == medium)
	{
		if ((*first)->next->sorted_index == big)
			rra(first);
		else
			sa(first);
		return (0);
	}
	return (1);
}

int first_biggest(element **first, unsigned long medium, unsigned long big)
{
	if ((*first)->sorted_index == big)
	{
		if ((*first)->next->sorted_index == medium)
		{
			ra(first);
			sa(first);
		}
		else
			ra(first);
		return (0);
	}
	return (1);
}
