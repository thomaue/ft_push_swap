/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:33:40 by tauer             #+#    #+#             */
/*   Updated: 2024/02/19 11:54:40 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// typedef struct t_element	t_t_element;

typedef struct s_element
{
	long				value;
	unsigned long		index;
	unsigned long		sorted_index;
	struct s_element	*next;
	struct s_element	*prev;
}						t_element;

// main
void					push_swap(char **tab);

// print
void					ft_putchar(char c);
void					ft_putstr(char *str);
void					ft_putnbr(int nb);
void					print_tab(char **tab);
// tab_num
char					**tab_tab_split(const char *s, char c);
char					**ft_split(char const *s, char c);
char					**tab_argv(int argc, char **argv);

// utils
size_t					ft_strlen(const char *str);
char					*ft_strdup(const char *s);
int						is_c(char c_s, char c);
unsigned int			count_word(char const *s, char c);
char					*mal_str(char const *s, char c, int *ptr);
unsigned long			list_size(t_element *first);
// long int				ft_atoi(const char *str);
bool					ft_atoi(const char *str, long *value);

t_element				*make_list(char **tab);

void					free_list(t_element *first);
void					free_all(t_element *first_a, t_element *first_b);
void					free_tab(char **tab);

void					print_line(void);
void					display(t_element *first, char c);
void					display_all(t_element *first_a, t_element *first_b);

void					swap_top(t_element **first);
void					push_to(t_element **first_src, t_element **first_dst);

void					correct_index(t_element *first);
void					correct_prev(t_element *first);
void					sorted_index(t_element *first);

void					rotate(t_element **first);
void					derotate(t_element **first);

unsigned long			sort_check(t_element *first, t_element *check);
int						bad_char(char **tab);
int						check_doublon(t_element *first);
bool					check_tab(char **tab);

void					little_sort(t_element **first);
void					medium_sort(t_element **first_a, t_element **first_b);
void					radix(t_element **first_a, t_element **first_b);

int						first_littlest(t_element **first, unsigned long little,
							unsigned long big);
int						first_medium(t_element **first, unsigned long medium,
							unsigned long big);
int						first_biggest(t_element **first, unsigned long medium,
							unsigned long big);

void					three_digit_sort(t_element **first);
void					two_digit_sort(t_element **first);
unsigned long			biggest_bit(t_element *first);
void					push_lowest(t_element **first_a, t_element **first_b,
							unsigned long sorted_index);
int						look_list(t_element *first, t_element *to_check);
int						ok_char(char c);

unsigned long			get_min(t_element *first);
unsigned long			get_medium(t_element *first);
unsigned long			get_max(t_element *first);

int						is_no_sorted(t_element **first);

void					sa(t_element **first);
void					sb(t_element **first);
void					ss(t_element **first_a, t_element **first_b);

void					pa(t_element **first_a, t_element **first_b);
void					pb(t_element **first_b, t_element **first_a);

void					rb(t_element **first);
void					ra(t_element **first);
void					rr(t_element **first_a, t_element **first_b);

void					rra(t_element **first);
void					rrb(t_element **first);
void					rrr(t_element **first_a, t_element **first_b);

#endif