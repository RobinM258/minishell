/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_tokenfind.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:08:06 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/22 15:36:09 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

int	mini_tokenfind(t_token *tokens, char c, int plop)
{
	while (tokens)
	{
		if ((mini_charfind(tokens->content, c) == 0
				&& mini_strlen(tokens->content) == 1 && !plop)
			|| (plop && mini_charfind(tokens->content, c) == 0
				&& mini_strlen(tokens->content) == 1
				&& tokens->altego == OTHER))
			return (1);
		tokens = tokens->next;
	}
	return (0);
}
