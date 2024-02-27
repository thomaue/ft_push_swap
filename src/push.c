/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:26:32 by tauer             #+#    #+#             */
/*   Updated: 2024/02/14 13:26:49 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//? fonctions push

void	pb(t_element **first_b, t_element **first_a)
{
	write(1, "pb\n", 3);
	push_to(first_a, first_b);
}

void	pa(t_element **first_a, t_element **first_b)
{
	write(1, "pa\n", 3);
	push_to(first_b, first_a);
}
