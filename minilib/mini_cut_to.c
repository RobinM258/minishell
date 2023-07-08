/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cut_to.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:02:05 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/04 11:02:13 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

char	*mini_cut_to(char *str, char c)
{
	int		i;
	int		size;
	char	*ret;

	size = mini_charfind(str, c);
	if (size == -1)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	i = -1;
	while (++i < size)
		ret[i] = str[i];
	ret[i] = '\0';
	return (ret);
}
