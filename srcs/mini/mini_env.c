/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:35:56 by romartin          #+#    #+#             */
/*   Updated: 2023/09/04 21:06:32 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

void	mini_lst_change(t_env **env, char *path)
{
	char	**split;
	t_env	*tmp;

	split = mini_ft_split(path, '=');
	tmp = *env;
	while (tmp)
	{
		if (mini_strcmp((tmp)->var, split[0], 0) == 0)
		{
			(tmp)->val = split[1];
			return ;
		}
		tmp = (tmp)->next;
	}
	mini_ft_lst_add_back(env, split[0], split[1]);
	free(split);
}

int	egal(t_token *tokens)
{
	int	j;

	while (tokens)
	{
		j = mini_charfind(tokens->content, '=');
		if (j > 0 && j != mini_strlen(tokens->content))
			return (1);
		tokens = tokens->next;
	}
	return (0);
}

int	check_env(t_minijoker *mini, t_token *tokens)
{
	while (tokens && !mini_is_intab(mini->sep, tokens->content, 0))
	{
		if (egal(tokens) == 0)
		{
			mini_putstr_fd(2, "env: ");
			mini_putstr_fd(2, tokens->content);
			mini_putstr_fd(2, ": Invalid argument\n");
			return (1);
		}
		tokens = tokens->next;
	}	
	return (0);
}

int	mini_env(t_minijoker *mini, int i)
{
	t_env	*env;
	t_env	*first;

	env = NULL;
	mini->tokens = mini->tokens->next;
	if (check_env(mini, mini->tokens) == 1)
		return (EXIT_FAILURE);
	while (mini->env_copy[i])
		mini_lst_change(&env, mini->env_copy[i++]);
	while (mini->tokens && !mini_is_intab(mini->sep, mini->tokens->content, 0))
	{
		mini_lst_change(&env, mini->tokens->content);
		mini->tokens = mini->tokens->next;
	}
	if (mini->tokens && !mini_is_intab(mini->sep, mini->tokens->content, 0))
		mini->tokens = mini->tokens->next;
	first = env;
	while (env)
	{
		mini_putstr_fd(mini->fdout, env->var);
		mini_putstr_fd(mini->fdout, "=");
		mini_putstr_fd(mini->fdout, env->val);
		mini_putstr_fd(mini->fdout, "\n");
		env = env->next;
	}
	mini_ft_lst_clear(first);
	return (SUCCESS);
}
