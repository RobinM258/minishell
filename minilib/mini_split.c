/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:39:31 by dgoubin           #+#    #+#             */
/*   Updated: 2023/09/11 20:32:33 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

static int	fill(char *str, char **charset, char *res, int *i)
{
	int		j;
	char	quote;

	quote = '\0';
	j = 0;
	while (str[*i])
	{
		if (!quote && (str[*i] == '\'' || str[*i] == '\"'))
			quote = str[*i];
		else if (quote && str[*i] == quote)
			quote = '\0';
		if (mini_is_intab(charset, &str[*i], 1) && !quote)
			break ;
		if (str[*i] == ' ' && !quote)
			break ;
		res[j++] = str[(*i)++];
	}
	return (j);
}

char	*ministrdup2(char *str, char **charset, int	*i)
{
	char	*res;
	int		size;
	int		j;

	j = 0;
	size = mini_len(str, charset, *i);
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	while (str[*i] && str[*i] == ' ')
		(*i)++;
	j = fill(str, charset, res, i);
	if (mini_is_intab(charset, &str[*i], 1) && j < 2)
	{
		if (mini_is_intab(charset, &str[*i], 1) == 2)
			res[j++] = str[(*i)++];
		res[j++] = str[(*i)++];
	}
	res[j] = '\0';
	return (res);
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

static t_token	*assignation(char *str, char **charset,
	t_token *tokens, int i)
{
	char	*content;
	int		plop;

	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (!str[i])
			break ;
		if (!mini_strcmp(" '|'", &str[i], 1)
			|| !mini_strcmp(" \"|\"", &str[i], 1))
			plop = PARAM;
		else
			plop = OTHER;
		content = ministrdup2(str, charset, &i);
		if (!mini_tokenadd_back(&tokens, mini_tokennew(content, plop)))
		{
			mini_tokenclear(tokens);
			return (NULL);
		}
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
	return (assignation(str, charset, NULL, 0));
}
