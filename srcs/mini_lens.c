/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lens.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:52:54 by dgoubin           #+#    #+#             */
/*   Updated: 2023/09/10 16:02:17 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

int	mini_len(char *str, char **charset, int i)
{
	int		j;
	char	quote;

	quote = '\0';
	j = i;
	while (str[j] && str[j] == ' ')
		j++;
	while (str[j])
	{
		if (!quote && (str[j] == '\'' || str[j] == '\"'))
			quote = str[j];
		else if (quote && str[j] == quote)
			quote = '\0';
		if (mini_is_intab(charset, &str[j], 1) && !quote)
			break ;
		if (str[j] == ' ' && !quote)
			break ;
		j++;
	}
	if (mini_is_intab(charset, &str[j], 1) && (j - i) < 2)
	{
		if (str[++j] == '<' || str[j] == '>')
			j++;
	}
	return (j - i);
}

int	mini_len2(char *str)
{
	int		i;
	int		size;
	char	quote;

	quote = '\0';
	i = 0;
	size = 0;
	while (str[i])
	{
		if (!quote && str[i] == '\'')
			quote = '\'';
		else if (quote && str[i] == quote)
			quote = '\0';
		else
			size++;
		i++;
	}
	return (size);
}

static void	mini_len3_quote(char *str, char *quote, int *i, int *size)
{
	if (!*quote)
		*quote = str[*i];
	else if (*quote == str[*i])
		*quote = '\0';
	else
		(*size)++;
}

static int	mini_len3_dol(t_minijoker *mini, int *i, int *size)
{
	char	*tmp;

	tmp = mini_cut_to2(&mini->tokens->content[(*i) + 1], "\' \" > >> << <");
	if (!tmp)
		return (-1);
	if (get_env(mini, tmp) != NULL)
		(*size) += mini_strlen(get_env(mini, tmp));
	else if (mini->tokens->content[(*i) + 1] == '?')
	{
		free(tmp);
		tmp = mini_itoa(mini->lerror);
		if (!tmp)
			return (-1);
		(*size) += mini_strlen(tmp);
	}
	if (mini_strlen(tmp) == 0)
		(*size)++;
	else
		*i += mini_strlen(tmp);
	free(tmp);
	return (0);
}

int	mini_len3(t_minijoker *mini, char *str)
{
	int		size;
	char	quote;
	int		i;

	size = 0;
	i = 0;
	quote = '\0';
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			mini_len3_quote(str, &quote, &i, &size);
		else if ((!quote || quote == '\"') && (str[i] == '$'))
		{
			if (mini_len3_dol(mini, &i, &size) == -1)
				return (-1);
		}
		else
			size++;
		i++;
	}
	return (size);
}
