/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_alpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:15:29 by dgoubin           #+#    #+#             */
/*   Updated: 2023/08/31 11:22:29 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

int	mini_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	mini_alphanum(char c)
{
	return (mini_alpha(c) || (c >= '0' && c <= '9'));
}

int	mini_has_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		if (mini_alpha(str[i++]))
			return (1);
	return (0);
}
