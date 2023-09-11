/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:34:13 by dgoubin           #+#    #+#             */
/*   Updated: 2023/09/10 15:44:01 by dgoubin          ###   ########.fr       */
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

char	*mini_cut_to2(char *str, char *charset)
{
	int		i;
	char	**tab;
	char	*res;

	i = 0;
	tab = mini_ft_split(charset, ' ');
	while (str[i++])
		if (mini_is_intab(tab, &str[i], 1) || str[i] == ' ')
			break ;
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (*mini_freetab(tab));
	i = 0;
	while (str[i])
	{
		if (mini_is_intab(tab, &str[i], 1) || str[i] == ' ')
			break ;
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	mini_freetab(tab);
	return (res);
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
	if (!mini->tokens)
		return ;
	parse_env(mini);
	mini->first = mini->tokens;
	if (mini->tokens && mini_strcmp(mini->tokens->content, "exit", 0) == 0)
	{
		mini->end = 1;
		return ;
	}
}
