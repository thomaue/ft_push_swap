/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:38:06 by tauer             #+#    #+#             */
/*   Updated: 2024/02/19 11:09:57 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

bool	check_tab(char **tab)
{
	size_t	i;

	i = 0;
	if (!tab)
		return (false);
	while (tab[i])
		i++;
	if (!bad_char(tab) || (i == 1 && !tab[i]))
	{
		free_tab(tab);
		return (false);
	}
	return (true);
}

int	check_doublon(t_element *first)
{
	t_element	*current;
	size_t		check;

	check = 0;
	current = first;
	while (current)
	{
		if (current->next && (current->value < current->next->value))
			check++;
		if (look_list(first, current) == 0)
		{
			free_list(first);
			return (0);
		}
		current = current->next;
	}
	if (check == list_size(first) - 1)
	{
		write(2, "[ALREADY SORTED]\n", 18);
		free_list(first);
		return (0);
	}
	return (1);
}

int	look_list(t_element *first, t_element *to_check)
{
	t_element	*current;

	current = first;
	while (current)
	{
		if (((current->index != to_check->index)
				&& (current->value == to_check->value)))
			return (0);
		else if (((current->value > 2147483647)
				|| (current->value < -2147483647)))
			return (0);
		current = current->next;
	}
	return (1);
}

int	bad_char(char **tab)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (tab[x])
	{
		y = 0;
		while (tab[x][y])
		{
			if ((tab[x][y] == '-' || tab[x][y] == '+') && (tab[x][y + 1] == '\0'
					|| tab[x][y + 1] == '+' || tab[x][y + 1] == '-'))
				return (0);
			if (ok_char(tab[x][y]) == 0)
			{
				write(2, "[BAD CHAR]\n", 12);
				return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}

unsigned long	sort_check(t_element *first, t_element *check)
{
	t_element		*current;
	unsigned long	sup_num;

	sup_num = 0;
	current = first;
	while (current)
	{
		if (current->index != check->index && current->value > check->value)
			sup_num++;
		current = current->next;
	}
	return (sup_num);
}
