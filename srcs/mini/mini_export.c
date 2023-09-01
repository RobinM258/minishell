/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:24:56 by romartin          #+#    #+#             */
/*   Updated: 2023/09/01 20:20:04 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

static char **mini_strs_copy(t_minijoker *mini, char *str)
{
	int i;
	char **tmp;
	char *var;

	i = mini_tablen(mini->env_copy);
	tmp = (char **)malloc(sizeof(char *) * (i + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (mini->env_copy[i])
	{
		var = mini_cut_to(mini->env_copy[i], '=');
		if (str && mini_strcmp(var, str, 0) == 0)
			tmp[i] = mini_strdup(str);
		else
			tmp[i] = mini_strdup(mini->env_copy[i]);
		free(var);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
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
			(tmp)->val = split[1];
			return ;
		}
		tmp = (tmp)->next;
	}
	mini_ft_lst_add_back(env, split[0], split[1]);
	free(split);
}

static int	egal(t_token *tokens)
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

int	check_export(t_minijoker *mini, t_token *tokens)
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

int	mini_export(t_minijoker *mini, int i)
{
	char *str;
	char **tmp;
	t_env	*env;
	t_env	*first;

	env = NULL;
	mini->tokens = mini->tokens->next;
	if (check_export(mini, mini->tokens) == 1)
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
		str = mini_strjoin(env->var, "=");
		str = mini_strjoin(str, env->val);
		tmp = mini_strs_copy(mini, str);
		mini_freetab(mini->env_copy);
		mini->env_copy = tmp;
		env = env->next;
	}
	mini_ft_lst_clear(first);
	return (SUCCESS);
}
