/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:41:59 by romartin          #+#    #+#             */
/*   Updated: 2023/07/01 18:14:58 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"
/*
PAS FINI
*/
int ft_unset(t_miniJoker *mini, int index)
{
	(void)index;
	char **tmp;
	char **str;
	char *a;
	int i;

	i = 0;
	if (!mini->tokens[1])
		return (EXIT_SUCCESS);
	str = ft_split(mini->tokens[1], '='); //malloc
	while (&mini->env_copy[i])
		i++;
	if (getEnv(mini, str[0]) != NULL)
		i--;
	tmp = (char **)malloc(sizeof(char *) * (i + 1)); //malloc
	while (&mini->env_copy[i])
	{
		a = ft_cut_to(mini->env_copy[i], '=');
		if (ft_strcmp(a, mini->tokens[1], 0) != 0)
			tmp[i] = ft_strdup(mini->tokens[1]);
		free(a);
		i++;
	}
	tmp[i] = NULL;
	mini->env_copy = tmp;
	freetab(str);
	return (EXIT_SUCCESS);
}