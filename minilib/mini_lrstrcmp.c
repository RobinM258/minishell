/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lrstrcmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:00:39 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/07 10:34:25 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

int	mini_lrstrcmp(char *s1, char *s2)
{
	int	i;

	if (!s1)
		return (-1);
	i = -1;
	while (s1[++i] && s2[i])
		if (s1[i] != s2[i])
			break ;
	if (s1[i] == '=')
		return (0);
	return (s1[i] - s2[i]);
}
