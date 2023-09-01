/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:49:09 by dgoubin           #+#    #+#             */
/*   Updated: 2023/08/31 12:57:55 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

int	is_func(t_minijoker *mini, char *str)
{
	char	**argv;
	int		i;

	argv = mini_ft_split(get_env(mini, "PATH"), ':');
	i = 0;
	while (argv[i])
	{
		if (mini_is_valid_func(argv[i], str))
		{
			freetab(argv);
			return (1);
		}
		i++;
	}
	freetab(argv);
	return (0);
}

void	clear_parse_env(char **tab, t_token *nt,
	t_minijoker *mini, t_token *tokens)
{
	freetab(tab);
	mini_tokenlast(nt)->next = tokens->next;
	nt->prev = tokens->prev;
	if (tokens->prev)
		tokens->prev->next = nt;
	else
		mini->tokens = nt;
	if (tokens->next)
		tokens->next->prev = nt;
}

void	parse_env_bis(t_minijoker *mini, char *tmp, t_token *tokens, int i)
{
	t_token		*nt;
	char		**tab;
	char		*low;

	nt = NULL;
	tab = mini_ft_split(get_env(mini, &tmp[1]), ' ');
	while (tab[++i])
	{
		if (!tokens->prev)
		{
			low = mini_tolower(tab[i]);
			if (is_func(mini, low))
				mini_tokenadd_back(&nt,
					mini_tokennew(mini_strdup(low), OTHER));
			else
				mini_tokenadd_back(&nt,
					mini_tokennew(mini_strdup(tab[i]), OTHER));
			free(low);
		}
		else
			mini_tokenadd_back(&nt,
				mini_tokennew(mini_strdup(tab[i]), OTHER));
	}
	clear_parse_env(tab, nt, mini, tokens);
}

void	parse_env(t_minijoker *mini, t_token *tokens)
{
	char	*tmp;

	while (tokens)
	{
		if (tokens->content[0] == '$' && tokens->content[1])
		{
			tmp = tokens->content;
			if (get_env(mini, &tmp[1]) != NULL)
				parse_env_bis(mini, tmp, tokens, -1);
			else if (mini_strcmp(tmp, "$?", 0) == 0)
				tokens->content = mini_itoa(mini->lerror);
			else
				tokens->content = mini_strdup(" ");
			free(tmp);
		}
		tokens = tokens->next;
	}
}
