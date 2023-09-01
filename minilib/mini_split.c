/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:05:53 by dgoubin           #+#    #+#             */
/*   Updated: 2023/08/31 12:26:24 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

static int	nb_of_words2(char *str, char **charset, int i, char quote)
{
	while (str[i] && !mini_is_intab(charset, &str[i], 1) && str[i] != ' ')
	{
		if (str[i] == '\"' || str[i] == '\'')
		{
			quote = str[i++];
			while (str[i] && str[i++] != quote)
				;
		}
		else
			i++;
	}
	return (i);
}

int	nb_of_words(char *str, char **charset)
{
	int	cpt;
	int	i;
	int	quote;

	quote = '\0';
	i = 0;
	cpt = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (!str[i])
			break ;
		cpt++;
		if (mini_is_intab(charset, &str[i], 1))
		{
			i++;
			if ((str[i] == '<' && str[i - 1] == '<')
				|| (str[i] == '>' && str[i - 1] == '>'))
				i++;
		}
		i = nb_of_words2(str, charset, i, quote);
	}
	return (cpt);
}

int	stris_encapsuled(char *str)
{
	char	quote;
	int		i;

	i = 0;
	quote = '\0';
	while (str[i])
	{
		if (quote == '\0' && (str[i] == '\'' || str[i] == '\"'))
			quote = str[i];
		else if (quote == str[i])
			quote = '\0';
		i++;
	}
	return (quote == '\0');
}

static t_token	*assignation(char *str, char **charset)
{
	int		ij[2];
	t_token	*tokens;
	char	*content;
	int		size;
	int		plop;

	size = nb_of_words(str, charset);
	ij[0] = 0;
	ij[1] = 0;
	tokens = NULL;
	while (ij[0] < size)
	{
		if (!mini_strcmp(" '|'", &str[ij[1]], 1)
			|| !mini_strcmp(" \"|\"", &str[ij[1]], 1))
			plop = PARAM;
		else
			plop = OTHER;
		content = ministrdup(str, charset, &ij[1]);
		if (!content)
			return (quit(tokens));
		if (!mini_tokenadd_back(&tokens, mini_tokennew(content, plop)))
			return (quit(tokens));
		ij[0]++;
	}
	return (tokens);
}

t_token	*mini_split(char *str, char **charset, int *error)
{	
	if (!str)
		return (NULL);
	if (!stris_encapsuled(str))
	{
		*error = QUOTE_ERROR;
		return (NULL);
	}
	return (assignation(str, charset));
}
