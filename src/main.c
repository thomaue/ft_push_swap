/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:27:21 by tauer             #+#    #+#             */
/*   Updated: 2024/02/19 12:04:23 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//! to display lists simply put this function line 34: :35
// display_all(first_a, first_b);

void	push_swap(char **tab)
{
	t_element	*first_a;
	t_element	*first_b;

	first_a = NULL;
	first_b = NULL;
	if (check_tab(tab))
		first_a = make_list(tab);
	if (first_a && check_doublon(first_a))
	{
		if (list_size(first_a) > 5)
			radix(&first_a, &first_b);
		else if (list_size(first_a) > 3)
			medium_sort(&first_a, &first_b);
		else
			little_sort(&first_a);
		free_all(first_a, first_b);
	}
	else
		write(2, "Error\n", 7);
}
// display_all(first_a, first_b);

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		if (argc == 2)
			push_swap(ft_split(argv[1], ' '));
		else
			push_swap(tab_argv(argc, argv));
	}
	else
	{
		write(2, "\t[NO ARGS]\n\n./push_swap ''... ... ...''\n", 41);
		write(2, "./push_swap   ... ... ...\n\n", 28);
	}
	return (0);
}
