/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:34:13 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/22 15:43:11 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

void	parse_dol(t_token *tokens)
{
	char	*tmp;
	int		i;
	t_token	*nt;

	i = 0;
	nt = NULL;
	while (tokens)
	{
		if (mini_charfind(tokens->content, '$') < mini_strlen(tokens->content))
		{
			tmp = tokens->content;
			while (tmp[i])
			{
				if (tmp[i] == '$')
				{
					mini_tokenadd_back(&nt,
						mini_tokennew(mini_cut_to(&tmp[i], ' '), OTHER));
					while (tmp[i] && tmp[i] != ' ')
						i++;
					if (tmp[i])
						i++;
				}
				if (!tmp[i])
					break ;
				mini_tokenadd_back(&nt,
					mini_tokennew(mini_cut_to(&tmp[i], '$'), OTHER));
				while (tmp[i] && tmp[i] != '$')
					i++;
			}
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

void	parse_env(t_minijoker *mini, t_token *tokens)
{
	char	*tmp;
	char	**tab;
	char	*low;
	int		i;
	t_token	*nt;

	while (tokens)
	{
		if (tokens->content[0] == '$' && tokens->content[1])
		{
			tmp = tokens->content;
			if (get_env(mini, &tmp[1]) != NULL)
			{
				nt = NULL;
				i = 0;
				tab = mini_ft_split(get_env(mini, &tmp[1]), ' ');
				while (tab[i])
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
					i++;
				}
				freetab(tab);
				mini_tokenlast(nt)->next = tokens->next;
				nt->prev = tokens->prev;
				if (tokens->prev)
					tokens->prev->next = nt;
				else
				{
					mini->tokens = nt;
				}
				if (tokens->next)
					tokens->next->prev = nt;
			}
			else if (mini_strcmp(tmp, "$?", 0) == 0)
				tokens->content = mini_itoa(mini->lerror);
			else
				tokens->content = mini_strdup(" ");
			free(tmp);
		}
		tokens = tokens->next;
	}
}

/* FONCTION QUI PARSE LES INPUT DE L'UTILISATEUR EN TOKENS */
/* */
/* prend en argument t_minijoker pour les tokens */
/* prend en argument une chaine de caractere qui est les input */
/*		de l'utilisateur */
/* renvoie 1 si le programme doit se fermer 0 sinon */
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
		mini->error = END;
		return ;
	}
}
