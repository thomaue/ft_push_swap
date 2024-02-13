/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:48:18 by tauer             #+#    #+#             */
/*   Updated: 2024/02/13 18:31:19 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

size_t ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int ft_isspace(char c)
{
	return (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v');
}

int ft_atoi(const char *str)
{
	size_t i;
	int sign;
	long int num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] >= '0' && str[i] <= '9')
		num = (num * 10) + (str[i++] - '0');
	return (num * sign);
}

int is_no_sorted(element **first)
{
	if (((*first)->sorted_index < (*first)->next->sorted_index) && (*first)->next->sorted_index < (*first)->next->next->sorted_index)
		return (0);
	return (1);
}
