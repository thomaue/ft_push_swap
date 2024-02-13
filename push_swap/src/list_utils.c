/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:37:02 by tauer             #+#    #+#             */
/*   Updated: 2024/02/13 18:30:43 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

element *make_first(char **tab)
{
	element *first_a;

	first_a = NULL;
	first_a = (element *)malloc(sizeof(element));
	if (!first_a)
		return (NULL);
	first_a->prev = NULL;
	first_a->next = NULL;
	first_a->index = 0;
	first_a->value = ft_atoi(tab[0]);
	return (first_a);
}

element *make_next(char **tab, element *current, unsigned int x)
{
	element *next;

	next = (element *)malloc(sizeof(element));
	if (!next)
		return (NULL);
	next->prev = current;
	next->next = NULL;
	next->index = x;
	next->value = ft_atoi(tab[x]);
	return (next);
}

element *core_list(char **tab)
{
	element *first_a;
	element *current;
	element *next;
	unsigned int x;

	first_a = make_first(tab);
	if (!first_a)
		return (NULL);
	current = first_a;
	x = 1;
	while (tab[x])
	{
		next = make_next(tab, current, x);
		if (!next)
			return (NULL);
		current->next = next;
		current = next;
		x++;
	}
	return (first_a);
}

element *make_list(char **tab)
{
	element *first_a;

	if (!tab)
		return (NULL);
	else if (!tab[0])
	{
		free(tab);
		write(1, "[NOT ENOUGH NUM]\n", 18);
		return (NULL);
	}
	first_a = core_list(tab);
	if (!first_a)
	{
		free(tab);
		write(1, "[MALLOC FAILED]\n", 17);
		return (NULL);
	}
	free_tab(tab);
	sorted_index(first_a);
	return (first_a);
}

unsigned long list_size(element *first)
{
	unsigned long size;
	element *current;

	if (!first)
		return (0);
	size = 0;
	current = first;
	while (current)
	{
		current = current->next;
		size++;
	}
	return (size);
}

int ok_char(char c)
{
	return (c == '-' || c == '+' || (c >= '0' && c <= '9'));
}
