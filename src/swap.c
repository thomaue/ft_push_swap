/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:26:57 by tauer             #+#    #+#             */
/*   Updated: 2024/02/14 13:27:08 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//? fonctions swap

void	sb(t_element **first)
{
	write(1, "sb\n", 3);
	swap_top(first);
}

void	sa(t_element **first)
{
	write(1, "sa\n", 3);
	swap_top(first);
}

void	ss(t_element **first_a, t_element **first_b)
{
	sa(first_a);
	sb(first_b);
}
