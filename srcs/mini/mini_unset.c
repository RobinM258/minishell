/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:41:59 by romartin          #+#    #+#             */
/*   Updated: 2023/07/07 10:04:30 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

static char	**copy_tab(t_minijoker *mini, int i)
{
	char	**new_env;
	char	*var;

	new_env = (char **)malloc(sizeof(char *) * (i + 1));
	if (!new_env)
		return (NULL);
	i = 0;
	while (mini->env_copy[i])
	{
		var = mini_cut_to(mini->env_copy[i], '=');
		if (mini_strcmp(var, mini->tokens->content, 0) != 0)
		{
			new_env[i] = mini_strdup(mini->env_copy[i]);
			if (!new_env[i])
			{
				printf("malloc faillure\n");
				mini_freetab(new_env);
				return (NULL);
			}
		}
		free(var);
		i++;
	}
	if (get_env(mini, mini->tokens->content) != NULL)
		i--;
	new_env[i] = NULL;
	return (new_env);
}

/* PAS FINI */
int	mini_unset(t_minijoker *mini)
{
	char	**new_env;
	int		i;

	i = 0;
	mini->tokens = mini->tokens->next;
	if (!mini->tokens->content)
		return (INPUT_ERROR);
	i = mini_tablen(mini->env_copy);
	if (get_env(mini, mini->tokens->content) != NULL)
		i--;
	new_env = copy_tab(mini, i);
	if (!new_env)
		return (MALLOC_ERROR);
	mini_freetab(mini->env_copy);
	mini->env_copy = new_env;
	return (SUCCESS);
}
