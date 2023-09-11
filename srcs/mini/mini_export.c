/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:59:45 by dgoubin           #+#    #+#             */
/*   Updated: 2023/09/11 21:12:15 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

static void	print_sorted(char **env)
{
	int		i;
	int		j;
	char	**closed;
	char	*low;

	i = 0;
	closed = (char **)malloc(sizeof(char *) * (mini_tablen(env) + 1));
	closed[i] = NULL;
	while (i < mini_tablen(env))
	{
		j = 0;
		low = NULL;
		while (env[j])
		{
			if (!mini_is_intab(closed, env[j], 0)
				&& (low == NULL || mini_strcmp(low, env[j], 0) > 0))
				low = env[j];
			j++;
		}
		closed[i++] = low;
		closed[i] = NULL;
		printf("%s\n", low);
	}
	free(closed);
}

static void	mini_lst_change(t_env **env, char *path)
{
	char	**split;
	t_env	*tmp;

	split = mini_ft_split(path, '=');
	tmp = *env;
	while (tmp)
	{
		if (mini_strcmp((tmp)->var, split[0], 0) == 0)
		{
			(tmp)->val = mini_strdup(split[1]);
			return ;
		}
		tmp = (tmp)->next;
	}
	mini_ft_lst_add_back(env, mini_strdup(split[0]), mini_strdup(split[1]));
	mini_freetab(split);
}

void	mini_export_bis(t_minijoker *mini)
{
	int		i;
	t_env	*env;
	t_env	*first;

	i = 0;
	env = NULL;
	first = NULL;
	while (mini->env_copy[i])
		mini_lst_change(&env, mini->env_copy[i++]);
	while (mini->tokens && !mini_is_intab(mini->sep, mini->tokens->content, 0))
	{
		if (jesaispas(mini, first, env, i) == 1)
			return ;
		i++;
		mini_lst_change(&env, mini->tokens->content);
		mini->tokens = mini->tokens->next;
	}
	jesaispas2(mini, first, env, i);
}

void	mini_export(t_minijoker *mini)
{
	mini->error = 0;
	mini->tokens = mini->tokens->next;
	if (!mini->tokens || !mini->tokens->content
		|| mini_is_intab(mini->sep, mini->tokens->content, 1))
	{
		print_sorted(mini->env_copy);
		return ;
	}
	mini_export_bis(mini);
}
