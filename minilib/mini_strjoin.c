/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:03:47 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/04 11:03:57 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

char	*mini_strjoin(char *s1, char *s2)
{
	int		i1;
	int		i2;
	int		i;
	int		j;
	char	*red;

	j = -1;
	i = -1;
	if (!s1 || !s2)
		return (0);
	i1 = mini_strlen(s1);
	i2 = mini_strlen(s2);
	red = malloc(sizeof(char) * (i1 + i2 + 1));
	if (!red)
		return (NULL);
	while (s1[++i])
		red[i] = s1[i];
	while (s2[++j])
	{
		red[i] = s2[j];
		i++;
	}
	red[i] = '\0';
	return (red);
}
