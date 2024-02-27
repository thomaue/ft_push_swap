/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:37:02 by tauer             #+#    #+#             */
/*   Updated: 2024/02/19 11:11:01 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_element	*make_first(char **tab)
{
	t_element	*first_a;

	first_a = NULL;
	first_a = (t_element *)malloc(sizeof(t_element));
	if (!first_a)
		return (NULL);
	first_a->prev = NULL;
	first_a->next = NULL;
	first_a->index = 0;
	if (ft_atoi(tab[0], &first_a->value))
	{
		free(first_a);
		return (NULL);
	}
	return (first_a);
}

t_element	*make_next(char **tab, t_element *current, unsigned int x)
{
	t_element	*next;

	next = (t_element *)malloc(sizeof(t_element));
	if (!next)
		return (NULL);
	next->prev = current;
	next->next = NULL;
	next->index = x;
	if (ft_atoi(tab[x], &next->value) == true)
	{
		free(next);
		return (NULL);
	}
	return (next);
}

t_element	*core_list(char **tab)
{
	t_element		*first_a;
	t_element		*current;
	t_element		*next;
	unsigned int	x;

	first_a = make_first(tab);
	if (!first_a)
		return (NULL);
	current = first_a;
	x = 1;
	while (tab[x])
	{
		next = make_next(tab, current, x);
		if (!next)
		{
			free_list(first_a);
			return (NULL);
		}
		current->next = next;
		current = next;
		x++;
	}
	return (first_a);
}

t_element	*make_list(char **tab)
{
	t_element	*first_a;

	first_a = NULL;
	if (!tab)
		return (NULL);
	else if (!tab[0])
	{
		free(tab);
		return (NULL);
	}
	first_a = core_list(tab);
	if (!first_a)
	{
		free_tab(tab);
		return (NULL);
	}
	free_tab(tab);
	sorted_index(first_a);
	return (first_a);
}

unsigned long	list_size(t_element *first)
{
	unsigned long	size;
	t_element		*current;

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
