/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:05:53 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/22 15:33:58 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

static t_token	*quit(t_token *tokens)
{
	mini_tokenclear(tokens);
	return (NULL);
}

int	mini_len(char *str, char **charset, int i)
{
	char	quote;
	int		size;

	size = 0;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i])
	{
		if (mini_is_intab(charset, &str[i], 1))
			break ;
		while (str[i] && !mini_is_intab(charset, &str[i], 1) && str[i] != ' ')
		{
			if (str[i] == '\"' || str[i] == '\'')
			{
				quote = str[i++];
				while (str[i] && str[i++] != quote)
					size++;
			}
			else
			{
				size++;
				i++;
			}
		}
		if (str[i] && str[i] == ' ')
			break ;
	}
	if (mini_is_intab(charset, &str[i], 1) && size == 0)
		size += mini_is_intab(charset, &str[i], 1);
	return (size);
}

char	*ministrdup(char *str, char **charset, int	*i)
{
	char	*res;
	int		size;
	char	quote;
	int		j;

	size = mini_len(str, charset, *i);
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	j = 0;
	while (str[*i] && str[*i] == ' ')
		(*i)++;
	while (str[*i])
	{
		if (mini_is_intab(charset, &str[*i], 1))
			break ;
		while (str[*i]
			&& !mini_is_intab(charset, &str[*i], 1) && str[*i] != ' ')
		{
			if (str[*i] == '\"' || str[*i] == '\'')
			{
				quote = str[(*i)++];
				while (str[*i] && str[(*i)++] != quote)
					res[j++] = str[(*i) - 1];
			}
			else
				res[j++] = str[(*i)++];
		}
		if (str[*i] && str[*i] == ' ')
			break ;
	}
	if (mini_is_intab(charset, &str[*i], 1) && size <= 2 && j < size)
	{
		if (mini_is_intab(charset, &str[*i], 1) == 2)
			res[j++] = str[(*i)++];
		res[j++] = str[(*i)++];
	}
	res[j] = '\0';
	return (res);
}

int	nb_of_words(char *str, char **charset)
{
	int	cpt;
	int	i;
	int	quote;

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

t_token	*mini_split(char *str, char **charset, int *error)
{
	char	*content;
	int		size;
	int		ij[2];
	t_token	*tokens;
	int		plop;

	tokens = NULL;
	if (!str)
		return (NULL);
	if (!stris_encapsuled(str))
	{
		*error = QUOTE_ERROR;
		return (NULL);
	}
	size = nb_of_words(str, charset);
	ij[0] = 0;
	ij[1] = 0;
	while (ij[0] < size)
	{
		if (!mini_strcmp(&str[ij[1]], " '|'", 1)
			|| !mini_strcmp(&str[ij[1]], " \"|\"", 1))
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
