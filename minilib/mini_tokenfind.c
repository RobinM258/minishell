/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_tokenfind.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:08:06 by dgoubin           #+#    #+#             */
/*   Updated: 2023/08/31 14:30:42 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

int	mini_tokenfindchar(t_token *tokens, char c, int plop)
{
	while (tokens)
	{
		if ((mini_charfind(tokens->content, c) == 0
				&& mini_strlen(tokens->content) == 1 && !plop)
			|| (plop && tokens->content[0] == c
				&& mini_strlen(tokens->content) == 1
				&& tokens->altego == OTHER))
			return (1);
		tokens = tokens->next;
	}
	return (0);
}

int	mini_tokenfindstr(t_token *tokens, char *str)
{
	char	*tmp;

	while (tokens)
	{
		tmp = mini_cut_to(str, '=');
		if (!tmp)
			return (-1);
		if (mini_strcmp(tmp, tokens->content, 0) == 0)
		{
			free(tmp);
			return (1);
		}
		tokens = tokens->next;
		free(tmp);
	}
	return (0);
}
