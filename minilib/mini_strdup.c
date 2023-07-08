/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:01:16 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/04 12:50:40 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

char	*mini_strdup(char *s1)
{
	int		cpt;
	char	*res;
	int		i;

	if (!s1)
		return (NULL);
	cpt = mini_strlen(s1);
	res = (char *)malloc(sizeof(char) * (cpt + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	res[i] = '\0';
	return (res);
}
