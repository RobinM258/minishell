/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:34:13 by dgoubin           #+#    #+#             */
/*   Updated: 2023/08/31 12:56:57 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

void	parse_dol_bis(t_token **nt, char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '$')
		{
			mini_tokenadd_back(nt,
				mini_tokennew(mini_cut_to(&tmp[i], ' '), OTHER));
			while (tmp[i] && tmp[i] != ' ')
				i++;
			if (tmp[i])
				i++;
		}
		if (!tmp[i])
			break ;
		mini_tokenadd_back(nt,
			mini_tokennew(mini_cut_to(&tmp[i], '$'), OTHER));
		while (tmp[i] && tmp[i] != '$')
			i++;
	}
}

void	parse_dol(t_token *tokens)
{
	char	*tmp;
	t_token	*nt;

	nt = NULL;
	while (tokens)
	{
		if (mini_charfind(tokens->content, '$') < mini_strlen(tokens->content))
		{
			tmp = tokens->content;
			parse_dol_bis(&nt, tmp);
			nt->prev = tokens->prev;
			mini_tokenlast(nt)->next = tokens->next;
			if (tokens->prev)
				tokens->prev->next = nt;
			if (tokens->next)
				tokens->next->prev = nt;
		}
		tokens = tokens->next;
	}
}

void	parser(t_minijoker *mini, char *input)
{
	if (!input)
	{
		mini->tokens = NULL;
		mini->error = END;
		return ;
	}
	mini->tokens = mini_split(input, mini->sep, &mini->error);
	parse_dol(mini->tokens);
	parse_env(mini, mini->tokens);
	if (mini->error == QUOTE_ERROR)
	{
		mini_putstr_fd(2, "parsing error: quote unclosed\n");
		return ;
	}
	if (mini->tokens && mini_strcmp(mini->tokens->content, "exit", 0) == 0)
	{
		mini->end = 1;
		return ;
	}
}
