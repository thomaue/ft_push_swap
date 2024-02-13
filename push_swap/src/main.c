/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:27:21 by tauer             #+#    #+#             */
/*   Updated: 2024/02/13 18:30:45 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void push_swap(char **tab)
{
	element *first_a;
	element *first_b;

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

		display_all(first_a, first_b);
		free_all(first_a, first_b);
	}
	else
		write(1, "[FAILURE]\n", 11);
}

int main(int argc, char **argv)
{
	if (argc >= 2)
	{
		if (argc == 2)
			push_swap(ft_split(argv[1], ' '));
		else
			push_swap(tab_argv(argc, argv));
	}
	else
		printf("\t[NO ARGS]\n\n%s ''... ... ...''\n%s   ... ... ...\n\n",
			   argv[0], argv[0]);
	return (0);
}
