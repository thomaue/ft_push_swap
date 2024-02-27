/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:12:14 by tauer             #+#    #+#             */
/*   Updated: 2024/02/14 13:23:35 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	free_list(t_element *first)
{
	t_element	*current;
	t_element	*temp;

	if (!first)
		return ;
	current = first;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
}

void	free_all(t_element *first_a, t_element *first_b)
{
	free_list(first_a);
	free_list(first_b);
}

void	free_tab(char **tab)
{
	int	x;

	x = 0;
	while (tab[x])
		free(tab[x++]);
	free(tab);
}
