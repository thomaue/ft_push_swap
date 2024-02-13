/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:33:40 by tauer             #+#    #+#             */
/*   Updated: 2024/02/13 18:32:56 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct element element;
struct element
{
	int value;
	unsigned long index;
	unsigned long sorted_index;
	struct element *next;
	struct element *prev;
};

// main
void push_swap(char **tab);

// print
void ft_putchar(char c);
void ft_putstr(char *str);
void ft_putnbr(int nb);
void print_tab(char **tab);
// tab_num
char **tab_tab_split(const char *s, char c);
char **ft_split(char const *s, char c);
char **tab_argv(int argc, char **argv);

// utils
size_t ft_strlen(const char *str);
char *ft_strdup(const char *s);
int is_c(char c_s, char c);
unsigned int count_word(char const *s, char c);
char *mal_str(char const *s, char c, int *ptr);
unsigned long list_size(element *first);
int ft_atoi(const char *str);


element *make_list(char **tab);

void free_list(element *first);
void free_all(element *first_a, element *first_b);
void free_tab(char **tab);

void print_line(void);
void display(element *first, char c);
void display_all(element *first_a, element *first_b);

void swap_top(element **first);
void push_to(element **first_src, element **first_dst);

void correct_index(element *first);
void correct_prev(element *first);
void sorted_index(element *first);

void rotate(element **first);
void derotate(element **first);

unsigned long sort_check(element *first, element *check);
int bad_char(char **tab);
int check_doublon(element *first);
int check_tab(char **tab);

void little_sort(element **first);
void medium_sort(element **first_a, element **first_b);
void radix(element **first_a, element **first_b);

int first_littlest(element **first, unsigned long little, unsigned long big);
int first_medium(element **first, unsigned long medium, unsigned long big);
int first_biggest(element **first, unsigned long medium, unsigned long big);


void three_digit_sort(element **first);
void two_digit_sort(element **first);
unsigned int biggest_bit(element *first);
void push_lowest(element **first_a, element **first_b, unsigned long sorted_index);
int	look_list(element *first, element *to_check);
int	ok_char(char c);

unsigned long get_min(element *first);
unsigned long get_medium(element *first);
unsigned long get_max(element *first);

int	is_no_sorted(element **first);

void sa(element **first);
void sb(element **first);
void ss(element **first_a, element **first_b);

void pa(element **first_a, element **first_b);
void pb(element **first_b, element **first_a);

void rb(element **first);
void ra(element **first);
void rr(element **first_a, element **first_b);

void rra(element **first);
void rrb(element **first);
void rrr(element **first_a, element **first_b);

#endif