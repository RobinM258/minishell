/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:03:47 by dgoubin           #+#    #+#             */
/*   Updated: 2023/09/10 14:48:13 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

char	*mini_strjoin(char *s1, char *s2)
{
	int		size;
	int		i;
	int		j;
	char	*red;

	j = 0;
	i = -1;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		size = 0;
	else
		size = mini_strlen(s1);
	if (s2)
		size += mini_strlen(s2);
	red = malloc(sizeof(char) * (size + 1));
	if (!red)
		return (NULL);
	while (s1 && s1[++i])
		red[i] = s1[i];
	while (s2 && s2[j])
		red[i++] = s2[j++];
	red[i] = '\0';
	return (red);
}
