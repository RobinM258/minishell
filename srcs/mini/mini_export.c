/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:24:56 by romartin          #+#    #+#             */
/*   Updated: 2023/09/05 22:01:44 by romartin         ###   ########.fr       */
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
			(tmp)->val = split[1];
			return ;
		}
		tmp = (tmp)->next;
	}
	mini_ft_lst_add_back(env, split[0], split[1]);
	free(split);
}

void	mini_export_bis(t_minijoker *mini)
{
	int		i;
	char	**tmp;
	t_env	*env = NULL;
	t_env	*first;
	char *str;
	char *s1;

	i = 0;
	
	if (mini->tokens->content[0] == '*')
	{
		 
	}
	while (mini->env_copy[i])
		mini_lst_change(&env, mini->env_copy[i++]);
	while (mini->tokens && !mini_is_intab(mini->sep, mini->tokens->content, 0))
	{
		if (mini->tokens->content[0] == '*')
		{
			mini_putstr_fd(2, "zsh: no matches found:");
			mini_putstr_fd(2, mini->tokens->content);
			mini_putstr_fd(2, "\n");
			mini->error = INPUT_ERROR;
			first = env;
			tmp = (char **)malloc(sizeof(char *) * (i + 1));
			i = 0;
			while (env)
			{
				s1 = mini_strjoin(env->var, "=");
				str = mini_strjoin(s1, env->val);
				tmp[i++] = str;
				free(s1);
				env = env->next;
			}
		tmp[i] = NULL;
		mini_freetab(mini->env_copy);
		mini->env_copy = tmp;
		free(first);
		return ;
		}
		if ((mini->tokens->content[0] >= '0' && mini->tokens->content[0] <= '9') || mini_strlen(mini->tokens->content) > mini_charfind(mini->tokens->content, '.') || mini->tokens->content[0] == '=')
		{
			mini_putstr_fd(2, "export: `");
			mini_putstr_fd(2, mini->tokens->content);
			mini_putstr_fd(2, "' : not a valid identifier ");
			
			mini_putstr_fd(2, "\n");
			mini->error = INPUT_ERROR;
			first = env;
			tmp = (char **)malloc(sizeof(char *) * (i + 1));
			i = 0;
			while (env)
			{
				s1 = mini_strjoin(env->var, "=");
				str = mini_strjoin(s1, env->val);
				tmp[i++] = str;
				free(s1);
				env = env->next;
			}
		tmp[i] = NULL;
		mini_freetab(mini->env_copy);
		mini->env_copy = tmp;
		free(first);
		return ;
		}
		i++;
		mini_lst_change(&env, mini->tokens->content);
		mini->tokens = mini->tokens->next;
	}
	if (mini->tokens && !mini_is_intab(mini->sep, mini->tokens->content, 0))
		mini->tokens = mini->tokens->next;
	first = env;
	tmp = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env)
	{	
		if (env->var && env->val)
		{
			s1 = mini_strjoin(env->var, "=");
			str = mini_strjoin(s1, env->val);
			tmp[i++] = str;
			free(s1);
		}
		env = env->next;
	}
	tmp[i] = NULL;
	mini_freetab(mini->env_copy);
	mini->env_copy = tmp;
	free(first);
 }

void	mini_export(t_minijoker *mini)
{
	mini->error = SUCCESS;
	mini->tokens = mini->tokens->next;
	if (!mini->tokens || !mini->tokens->content
		|| mini_is_intab(mini->sep, mini->tokens->content, 1))
	{
		print_sorted(mini->env_copy);
		return ;
	}
	mini_export_bis(mini);
}
