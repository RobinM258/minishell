/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_tolower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:22:54 by iqiyu             #+#    #+#             */
/*   Updated: 2023/07/22 15:37:52 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

char	*mini_tolower(char *str)
{
	char	*res;
	int		i;

	if (!str)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (mini_strlen(str) + 1));
	i = 0;
	if (!res)
		return (NULL);
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			res[i] = str[i] + ('a' - 'A');
		else
			res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
