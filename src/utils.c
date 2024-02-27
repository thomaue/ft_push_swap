/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:48:18 by tauer             #+#    #+#             */
/*   Updated: 2024/02/19 11:54:52 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v');
}

// long int	ft_atoi(const char *str)
// {
// 	size_t		i;
// 	int			sign;
// 	long int	num;

// 	i = 0;
// 	sign = 1;
// 	num = 0;
// 	while (str[i] && ft_isspace(str[i]))
// 		i++;
// 	if (str[i] == '-' || str[i] == '+')
// 		if (str[i++] == '-')
// 			sign *= -1;
// 	while (str[i] >= '0' && str[i] <= '9')
// 		num = (num * 10) + (str[i++] - '0');
// 	return (num * sign);
// }

bool	ft_atoi(const char *str, long *out_value)
{
	int	sign;
	int	value;
	int	i;

	value = 0;
	sign = 1;
	i = 0;
	*out_value = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str && str[i] >= '0' && str[i] <= '9')
	{
		if (value > (__INT_MAX__ - str[i] + '0') / 10)
			return (true);
		value = (value * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (true);
	*out_value = value * sign;
	return (false);
}

int	is_no_sorted(t_element **first)
{
	if (((*first)->sorted_index < (*first)->next->sorted_index)
		&& (*first)->next->sorted_index < (*first)->next->next->sorted_index)
		return (0);
	return (1);
}

int	ok_char(char c)
{
	return (c == '-' || c == '+' || (c >= '0' && c <= '9'));
}
