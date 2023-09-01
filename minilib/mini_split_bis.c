/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_split_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:24:05 by dgoubin           #+#    #+#             */
/*   Updated: 2023/08/31 14:01:36 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

t_token	*quit(t_token *tokens)
{
	mini_tokenclear(tokens);
	return (NULL);
}

static void	mini_len2(char *str, char **charset, int *isize, char quote)
{
	while (str[isize[1]]
		&& !mini_is_intab(charset, &str[isize[1]], 1) && str[isize[1]] != ' ')
	{
		if (str[isize[1]] == '\"' || str[isize[1]] == '\'')
		{
			quote = str[(isize[1])++];
			while (str[isize[1]] && str[(isize[1])++] != quote)
				(isize[0])++;
		}
		else
		{
			(isize[1])++;
			(isize[0])++;
		}
	}
}

int	mini_len(char *str, char **charset, int i)
{
	char	quote;
	int		*isize;
	int		r;

	isize = (int *)malloc(sizeof(int) * (2));
	quote = '\0';
	isize[0] = 0;
	isize[1] = i;
	while (str[isize[1]] && str[isize[1]] == ' ')
		isize[1]++;
	while (str[isize[1]])
	{
		if (mini_is_intab(charset, &str[isize[01]], 1))
			break ;
		mini_len2(str, charset, isize, quote);
		if (str[isize[1]] && str[isize[1]] == ' ')
			break ;
	}
	if (mini_is_intab(charset, &str[isize[1]], 1) && isize[0] == 0)
		isize[0] += mini_is_intab(charset, &str[isize[1]], 1);
	r = isize[0];
	free(isize);
	return (r);
}

static int	fill(char *str, char **charset, char *res, int *i)
{
	char	quote;
	int		j;

	j = 0;
	while (str[*i])
	{
		if (mini_is_intab(charset, &str[*i], 1))
			break ;
		while (str[*i]
			&& !mini_is_intab(charset, &str[*i], 1) && str[*i] != ' ')
		{
			if ((str[*i] == '\"' || str[*i] == '\'') && !quote)
			{
				quote = str[(*i)++];
				while (str[*i] && str[(*i)++] != quote)
					res[j++] = str[(*i) - 1];
				quote = '\0';
			}
			else
				res[j++] = str[(*i)++];
		}
		if (str[*i] && str[*i] == ' ')
			break ;
	}
	return (j);
}

char	*ministrdup(char *str, char **charset, int	*i)
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
	if (mini_is_intab(charset, &str[*i], 1) && size <= 2 && j < size)
	{
		if (mini_is_intab(charset, &str[*i], 1) == 2)
			res[j++] = str[(*i)++];
		res[j++] = str[(*i)++];
	}
	res[j] = '\0';
	return (res);
}
