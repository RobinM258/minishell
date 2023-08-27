/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:24:56 by romartin          #+#    #+#             */
/*   Updated: 2023/07/20 12:40:23 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

static char	**copy_tab(t_minijoker *mini, char **str, int i)
{
	char	**tmp;
	char	*var;

	tmp = (char **)malloc(sizeof(char *) * (i + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (mini->env_copy[i])
	{
		var = mini_cut_to(mini->env_copy[i], '=');
		if (mini_strcmp(var, str[0], 0) == 0)
			tmp[i] = mini_strdup(mini->tokens->content);
		else
			tmp[i] = mini_strdup(mini->env_copy[i]);
		free(var);
		i++;
	}
	if (get_env(mini, str[0]) == NULL)
		tmp[i++] = mini_strdup(mini->tokens->content);
	tmp[i] = NULL;
	return (tmp);
}

/* Gestion de la fonction export  */
/* prend mini en argument pour les token */
/* renvoie 1 si elle réussi */
void	mini_export(t_minijoker *mini)
{
	char	**str;
	char	**tmp;
	int		i;

	mini->error = SUCCESS;
	mini->tokens = mini->tokens->next;
	if (!mini->tokens || !mini->tokens->content
		|| mini_is_intab(mini->sep, mini->tokens->content, 1))
	{
		i = 0;
		while (mini->env_copy[i])
		{
			printf("%s\n", mini->env_copy[i]);
			i++;
		}
		return ;
	}
	str = mini_ft_split(mini->tokens->content, '=');
	if (!str)
	{
		mini->error = MALLOC_ERROR;
		mini_putstr_fd(2, "export: malloc failed");
		return ;
	}
	if (!str[0])
	{
		mini_freetab(str);
		return ;
	}
	if (mini->tokens->content[0] == '=')
	{
		mini_putstr_fd(2, "export: `");
		mini_putstr_fd(2, mini->tokens->content);
		mini_putstr_fd(2, "': not a valid identifier\n");
		mini->error = INPUT_ERROR;
	}
	i = mini_tablen(mini->env_copy);
	if (get_env(mini, str[0]) == NULL)
		i++;
	tmp = copy_tab(mini, str, i);
	if (!tmp)
	{
		mini->error = MALLOC_ERROR;
		mini_putstr_fd(2, "export: malloc failed");
		return ;
	}
	mini_freetab(mini->env_copy);
	mini->env_copy = tmp;
	mini_freetab(str);
	mini->tokens = mini->tokens->next;
}
