/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:27:48 by tauer             #+#    #+#             */
/*   Updated: 2024/02/14 13:23:45 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//! Intervertit les 2 premiers éléments au sommet de la pile.
// Ne fait rien s’il n’y en a qu’un ou aucun.

void	swap_top(t_element **first)
{
	t_element	*first_dup;
	t_element	*second_dup;
	t_element	*temp;

	temp = NULL;
	first_dup = NULL;
	second_dup = NULL;
	if (*first && (*first)->next)
	{
		first_dup = (*first);
		second_dup = (*first)->next;
		if ((*first)->next->next)
			temp = (*first)->next->next;
		(*first) = second_dup;
		(*first)->next = first_dup;
		(*first)->next->next = temp;
		correct_index(*first);
		correct_prev(*first);
	}
}

//! push d'une stack a l'autre
// Ne fait rien s’il n’y en a qu’un ou aucun.

void	push_to(t_element **first_src, t_element **first_dst)
{
	t_element	*dup;
	t_element	*temp;

	temp = NULL;
	if (!(*first_src))
		return ;
	dup = (*first_src);
	if ((*first_src)->next)
		(*first_src) = (*first_src)->next;
	else
		(*first_src) = NULL;
	if ((*first_dst))
		temp = (*first_dst);
	(*first_dst) = dup;
	(*first_dst)->next = temp;
	(*first_dst)->prev = NULL;
	correct_index((*first_dst));
	correct_index((*first_src));
	correct_prev((*first_dst));
	correct_prev((*first_src));
}

//! rotate toute la pile le premier devient le dernier
// Ne fait rien s’il n’y en a qu’un ou aucun.

void	rotate(t_element **first)
{
	t_element	*current;
	t_element	*dup;

	current = NULL;
	dup = NULL;
	if (!(*first) || !(*first)->next)
		return ;
	current = (*first);
	dup = (*first);
	(*first) = (*first)->next;
	while (current->next)
		current = current->next;
	current->next = dup;
	current->next->next = NULL;
	correct_index((*first));
	correct_prev((*first));
}

//! rotate toute la pile le dernier devient le premier
// Ne fait rien s’il n’y en a qu’un ou aucun.

void	derotate(t_element **first)
{
	t_element	*current;
	t_element	*dup;

	current = NULL;
	dup = NULL;
	current = (*first);
	if (!(*first) || !(*first)->next)
		return ;
	while (current->next)
		current = current->next;
	dup = current;
	dup->prev->next = NULL;
	current = (*first);
	(*first) = dup;
	(*first)->next = current;
	(*first)->next->prev = (*first);
	correct_index((*first));
	correct_prev((*first));
}
