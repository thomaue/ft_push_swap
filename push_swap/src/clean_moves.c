/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:18:57 by tauer             #+#    #+#             */
/*   Updated: 2024/02/13 18:30:34 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//? fonction reverse rotate

void rrb(element **first)
{
	write(1, "rrb\n", 4);
	derotate(first);
}

void rra(element **first)
{
	write(1, "rra\n", 4);
	derotate(first);
}

void rrr(element **first_a, element **first_b)
{
	write(1, "rrr\n", 4);
	rra(first_a);
	rrb(first_b);
}

//? fonctions rotate

void rb(element **first)
{
	write(1, "rb\n", 3);
	rotate(first);
}

void ra(element **first)
{
	write(1, "ra\n", 3);
	rotate(first);
}

void rr(element **first_a, element **first_b)
{
	write(1, "rr\n", 3);
	ra(first_a);
	rb(first_b);
}

//? fonctions push

void pb(element **first_b, element **first_a)
{
	write(1, "pb\n", 3);
	push_to(first_a, first_b);
}

void pa(element **first_a, element **first_b)
{
	write(1, "pa\n", 3);
	push_to(first_b, first_a);
}

//? fonctions swap

void sb(element **first)
{
	write(1, "sb\n", 3);
	swap_top(first);
}

void sa(element **first)
{
	write(1, "sa\n", 3);
	swap_top(first);
}

void ss(element **first_a, element **first_b)
{
	sa(first_a);
	sb(first_b);
}
