/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_strcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:02:43 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/05 13:16:37 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

int	mini_strcpy(char *src, char *dst)
{
	int	i;

	if (!src || !dst)
		return (-1);
	i = -1;
	while (src[++i] && dst[i])
		dst[i] = src[i];
	return (i);
}
