/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:35:56 by romartin          #+#    #+#             */
/*   Updated: 2023/08/27 22:16:06 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"
void	testprint(t_env *env)
{
	while (env)
	{
		printf("%s=%s\n", env->var, env->val);
		env = env->next;
	}
}
t_env	*ft_lst_new(char *var, char *val)
{
	t_env	*tmp;

	tmp = malloc(sizeof(t_env));
	if (!tmp)
		exit(EXIT_FAILURE);
	tmp->val = val;
	tmp->var = var;
	tmp->next = NULL;
	return (tmp);
}

t_env	*ft_lstlast(t_env *env)
{
	while (env->next)
	{
		if (env->next == NULL)
			return (env);
		env = env->next;
	}
	return (env);
}

void	ft_lstadd_back(t_env **lst, char *var, char *val)
{
	t_env	*new;

	new = ft_lst_new(var, val);
	if (lst)
	{
		if (*lst)
			ft_lstlast(*lst)->next = new;
		else
		{
			*lst = new;
		}
	}
}

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
	ft_lstadd_back(env, split[0], split[1]);
}


char	*get_env(t_minijoker *mini, char *str)
{
	int	i;

	i = 0;
	while (mini->env_copy[i])
	{
		if (mini_lrstrcmp(mini->env_copy[i++], str) == 0)
			return (&mini->env_copy[i - 1]
				[mini_charfind(mini->env_copy[i - 1], '=') + 1]);
	}
	return (NULL);
}

int egal(t_token *tokens)
{
	int	j;

	while(tokens)
	{
		j = mini_charfind(tokens->content, '=');
		if (j > 0 && j != mini_strlen(tokens->content))
			return (1);
		tokens = tokens->next;
	}
	return(0);
}
int check_env(t_token *tokens)
{
	while (tokens)
	{
		if (egal(tokens) == 0)
		{
			mini_putstr_fd(2, "env: ");
			mini_putstr_fd(2, tokens->content);
			mini_putstr_fd(2, ": Invalid argument\n");
			return (EXIT_FAILURE);
		}
		tokens = tokens->next;
	}	
	return (EXIT_SUCCESS);
}
int parsing_env(t_minijoker *mini, t_token *tokens)
{
	char **str;
	int l;
	int i;
	
	i = -1;
	l = mini_tablen(mini->env_copy);
	while (tokens)
	{
		l++;
		tokens = tokens->next;
	}
	str = (char **)malloc(sizeof(char *) * (l + 1));
	if (!str)
		return (MALLOC_ERROR);
	
	return (0);
}

int	mini_env(t_minijoker *mini)
{
	t_env *env = NULL;
	int	i;

	i = 0;
	parsing_env(mini, mini->tokens);
	mini->tokens = mini->tokens->next;
	if (check_env(mini->tokens) == 1)
		return (EXIT_FAILURE);
	while (mini->env_copy[i])
	{
		mini_lst_change(&env, mini->env_copy[i]);
		i++;
	}
	while (mini->tokens)
	{
		mini_lst_change(&env, mini->tokens->content);
		mini->tokens = mini->tokens->next;
	}
	if (mini->tokens)
		mini->tokens = mini->tokens->next;
	while (env)
	{
		mini_putstr_fd(mini->fdout, env->var);
		mini_putstr_fd(mini->fdout, "=");
		mini_putstr_fd(mini->fdout, env->val);
		mini_putstr_fd(mini->fdout, "\n");
		env = env->next;
	}
	return (SUCCESS);

}
