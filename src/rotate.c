/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:25:59 by tauer             #+#    #+#             */
/*   Updated: 2024/02/14 13:26:23 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//? fonctions rotate

void	rb(t_element **first)
{
	write(1, "rb\n", 3);
	rotate(first);
}

void	ra(t_element **first)
{
	write(1, "ra\n", 3);
	rotate(first);
}

void	rr(t_element **first_a, t_element **first_b)
{
	write(1, "rr\n", 3);
	ra(first_a);
	rb(first_b);
}
