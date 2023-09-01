/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:42:06 by dgoubin           #+#    #+#             */
/*   Updated: 2023/08/31 13:42:39 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

char	*get_env_bis(t_minijoker *mini, char *str)
{
	int	i;

	i = 0;
	while (mini->env_copy[i])
	{
		if (mini_strcmp(mini->env_copy[i++], str, 0) == 0)
			return (&mini->env_copy[i - 1]
				[mini_charfind(mini->env_copy[i - 1], '=') + 1]);
	}
	return (NULL);
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
