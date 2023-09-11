/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:22:41 by dgoubin           #+#    #+#             */
/*   Updated: 2023/09/10 16:00:24 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

static void	parse_bis_bis(t_minijoker *mini, int *i, int *j, char *str)
{
	char	*tmp;

	tmp = mini_cut_to2(&mini->tokens->content[(*i) + 1], "\' \" > >> << <");
	if (get_env(mini, tmp) != NULL)
	{
		str[*j] = '\0';
		mini_stradd(str, get_env(mini, tmp));
		*j = mini_strlen(str);
	}
	else if (mini->tokens->content[(*i) + 1] == '?')
	{
		str[*j] = '\0';
		free(tmp);
		tmp = mini_itoa(mini->lerror);
		if (!tmp)
			return ;
		mini_stradd(str, tmp);
		*j = mini_strlen(str);
	}
	if (mini_strlen(tmp) == 0)
		str[(*j)++] = mini->tokens->content[(*i)++];
	else
	*i += mini_strlen(tmp) + 1;
	free(tmp);
}

static void	parse_bis(t_minijoker *mini, int i, int j, int size)
{
	char	*str;
	char	quote;

	str = (char *)malloc(sizeof(char) * (size + 1));
	quote = '\0';
	while (mini->tokens->content[i])
	{
		if (mini->tokens->content[i] == '\''
			|| mini->tokens->content[i] == '\"')
		{
			if (!quote)
				quote = mini->tokens->content[i++];
			else if (quote == mini->tokens->content[i++])
				quote = '\0';
			else
				str[j++] = mini->tokens->content[i - 1];
		}
		else if ((!quote || quote == '\"') && (mini->tokens->content[i] == '$'))
			parse_bis_bis(mini, &i, &j, str);
		else
			str[j++] = mini->tokens->content[i++];
	}
	str[j] = '\0';
	free(mini->tokens->content);
	mini->tokens->content = str;
}

void	parse_env(t_minijoker *mini)
{
	t_token	*token;
	int		size;

	token = mini->tokens;
	while (mini->tokens)
	{
		size = mini_len3(mini, mini->tokens->content);
		if (size == -1)
		{
			mini->error = MALLOC_ERROR;
			return ;
		}
		if (size != mini_strlen(mini->tokens->content))
			parse_bis(mini, 0, 0, size);
		mini->tokens = mini->tokens->next;
	}
	mini->tokens = token;
}
