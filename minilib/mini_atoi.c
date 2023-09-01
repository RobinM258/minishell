/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:10:24 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/31 17:10:59 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

int	mini_atoi(const char *str)
{
	int	res;
	int	minus;

	res = 0;
	minus = 1;
	while (*str == 32 || *str == 9 || *str == 10 || *str == 12 || *str == 13
		|| *str == 11)
		str++;
	if (*str == '-' || *str == '+')
		if (*(str++) == '-')
			minus = -1;
	while (*str >= '0' && *str <= '9')
		res = (res * 10) + *(str++) - '0';
	return (res * minus);
}
