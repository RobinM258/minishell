/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_strcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:01:40 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/31 13:58:48 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"
#include <stdio.h>

int	mini_strcmp(char *s1, char *s2, int ended)
{
	int	i;

	if (!s1)
		return (-1);
	i = -1;
	while (s1[++i] && s2[i])
		if (s1[i] != s2[i])
			break ;
	if (ended && s1[i] == '\0')
		return (0);
	return (s1[i] - s2[i]);
}
