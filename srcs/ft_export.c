/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:24:56 by romartin          #+#    #+#             */
/*   Updated: 2023/07/01 18:01:00 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

 /* 
 Gestion de la fonction export 
 prend mini en argument pour les token	/!\ index
 renvoie 1 si elle réussi
 */

int ft_export(t_miniJoker *mini, int index)
{
	char **str;
	char **tmp;
	int i;
	char *a;

	(void)index;
	if (!mini->tokens[1])
	{
		ft_env(mini);
		return (EXIT_SUCCESS);
	}
	str = ft_split(mini->tokens[1], '='); //malloc
	if (!str[0] || !str[1])
	{
		freetab(str);
		return (EXIT_FAILLURE);
	}
	i = 0;
	while (mini->env_copy[i])
		i++;
	if (getEnv(mini, str[0]) == NULL)
		i++;
	tmp = (char **)malloc(sizeof(char *) * (i + 1)); //malloc
	i = 0;
	while (mini->env_copy[i])
	{
		a = ft_cut_to(mini->env_copy[i], '=');
		if (ft_strcmp(a, str[0], 0) == 0)
			tmp[i] = ft_strdup(mini->tokens[1]);
		else 
			tmp[i] = ft_strdup(mini->env_copy[i]);
		free(a);
		i++;
	}
	if (getEnv(mini, str[0]) == NULL)
		tmp[i++] = ft_strdup(mini->tokens[1]);
	tmp[i] = NULL;
	freetab(mini->env_copy);
	mini->env_copy = tmp;
	freetab(str);
	return (EXIT_SUCCESS);
}
