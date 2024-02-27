/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:25:27 by tauer             #+#    #+#             */
/*   Updated: 2024/02/14 13:25:52 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//? fonction reverse rotate

void	rrb(t_element **first)
{
	write(1, "rrb\n", 4);
	derotate(first);
}

void	rra(t_element **first)
{
	write(1, "rra\n", 4);
	derotate(first);
}

void	rrr(t_element **first_a, t_element **first_b)
{
	write(1, "rrr\n", 4);
	rra(first_a);
	rrb(first_b);
}
