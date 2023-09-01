/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:41:59 by romartin          #+#    #+#             */
/*   Updated: 2023/08/31 14:32:44 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

static int	not_valid(char *str)
{
	int	i;

	if (!str)
		return (0);
	if (!mini_alpha(str[0]))
		return (0);
	i = 0;
	while (str[i])
		if (!mini_alphanum(str[i++]))
			return (0);
	if (mini_charfind(str, '=') > mini_strlen(str))
		return (0);
	return (1);
}

static char	**exit_unset(char **new_env)
{
	mini_putstr_fd(2, "malloc faillure\n");
	mini_freetab(new_env);
	return (NULL);
}

static char	**copy_tab(t_minijoker *mini, int i, int j)
{
	char	**new_env;

	new_env = (char **)malloc(sizeof(char *) * (i + 1));
	if (!new_env)
		return (NULL);
	i = -1;
	while (mini->env_copy[++i])
	{
		if (mini_tokenfindstr(mini->tokens, mini->env_copy[i]) == 0)
		{
			new_env[j] = mini_strdup(mini->env_copy[i]);
			if (!new_env[j++])
				return (exit_unset(new_env));
		}
	}
	while (mini->tokens && !mini_is_intab(mini->sep, mini->tokens->content, 0))
		mini->tokens = mini->tokens->next;
	new_env[j] = NULL;
	return (new_env);
}

static void	mini_unset_bis(t_minijoker *mini, t_token *tmp, int *i)
{
	while (tmp && !mini_is_intab(mini->sep, tmp->content, 0))
	{
		if (get_env_bis(mini, tmp->content) != NULL)
		{
			printf("%s\n", tmp->content);
			(*i)--;
		}
		else if (!not_valid(tmp->content))
		{
			mini_putstr_fd(2, "unset: `");
			mini_putstr_fd(2, tmp->content);
			mini_putstr_fd(2, "': not a valid identifier\n");
		}
		tmp = tmp->next;
	}
}

void	mini_unset(t_minijoker *mini)
{
	char	**new_env;
	t_token	*tmp;
	int		i;

	i = 0;
	mini->error = SUCCESS;
	mini->tokens = mini->tokens->next;
	if (!mini->tokens)
		return ;
	if (!mini->tokens->content)
	{
		mini->error = INPUT_ERROR;
		return ;
	}
	i = mini_tablen(mini->env_copy);
	tmp = mini->tokens;
	mini_unset_bis(mini, tmp, &i);
	new_env = copy_tab(mini, i, 0);
	if (!new_env)
		return ;
	mini_freetab(mini->env_copy);
	mini->env_copy = new_env;
}
