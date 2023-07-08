/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:35:56 by romartin          #+#    #+#             */
/*   Updated: 2023/07/07 16:00:42 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

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

int	mini_env(t_minijoker *mini)
{
	int	i;

	i = 0;
	while (mini->env_copy[i])
	{
		printf("%s\n", mini->env_copy[i]);
		i++;
	}
	mini->tokens = mini->tokens->next;
	return (SUCCESS);
}
