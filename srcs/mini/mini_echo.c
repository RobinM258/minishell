/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:43:06 by iqiyu             #+#    #+#             */
/*   Updated: 2023/07/07 15:59:06 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

/* Gestion de la fonction echo */
/* prend mini en argument pour les token */
/* renvoie 1 si elle réussi */
int	mini_echo(t_minijoker *mini)
{
	int	lr;

	mini->tokens = mini->tokens->next;
	lr = 1;
	if (mini->tokens && mini_strcmp(mini->tokens->content, "-n", 0) == 0)
	{
		lr = 0;
		mini->tokens = mini->tokens->next;
	}
	while (mini->tokens && !mini_is_intab(mini->sep, mini->tokens->content))
	{
		printf("%s", mini->tokens->content);
		if (mini->tokens->next && mini->tokens->content && !mini_is_intab(mini->sep, mini->tokens->next->content))
			printf(" ");
		mini->tokens = mini->tokens->next;
	}
	if (lr)
		printf("\n");
	return (SUCCESS);
}
