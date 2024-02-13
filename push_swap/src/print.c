/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:58:45 by tauer             #+#    #+#             */
/*   Updated: 2024/02/13 18:30:53 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void print_tab(char **tab)
{
	int x;
	int y;

	x = 0;
	y = 0;
	ft_putstr("[PUSH-SWAP : TAB]\n\n");
	while (tab[x])
	{
		y = 0;
		ft_putchar('[');
		ft_putnbr(x);
		ft_putstr("] : ");
		while (tab[x][y])
		{
			write(1, &tab[x][y], 1);
			y++;
		}
		ft_putchar('\n');
		x++;
	}
	ft_putchar('[');
	ft_putnbr(x);
	ft_putstr("] : NULL");
	write(1, "\n", 1);
}

void display(element *first, char c)
{
	element *current;

	current = NULL;
	printf(" ⭐ [\033[38;5;171mDISPLAY STACK %c\033[0m]\n", c);

	print_line();
	if (!first)
	{
		printf("|[\033[38;5;196mNULL\033[0m]<-[\033[38;5;196mNULL\033[0m]->[\033[38;5;196mNULL\033[0m] |\n");
		print_line();
		return;
	}
	current = first;
	printf("|[PREV   So In Va   NEXT]|\n");
	while (current)
	{
		printf("|");
		if (current->prev)
		{
			printf("[\033[38;5;88m%lu\033[0m", current->prev->index);
			printf(":\033[38;5;160m%d\033[0m]<-", current->prev->value);
		}
		else
			printf("\033[38;5;196m[NULL]\033[0m<-");
		printf("[\033[38;5;85m%lu\033[0m:", current->sorted_index);
		printf("\033[38;5;220m%lu\033[0m:", current->index);
		printf("\033[38;5;75m%d\033[0m]", current->value);
		if (current->next)
		{
			printf("->[\033[38;5;28m%lu\033[0m", current->next->index);
			printf(":\033[38;5;156m%d\033[0m]", current->next->value);
			// printf(" ");
		}
		else
			printf("->\033[38;5;196m[NULL]\033[0m");
		current = current->next;
		printf("|\n");
	}
	print_line();
}

void display_all(element *first_a, element *first_b)
{
	display(first_a, 'A');
	display(first_b, 'B');
}
