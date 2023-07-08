/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:53:42 by iqiyu             #+#    #+#             */
/*   Updated: 2023/07/07 09:51:22 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

/* FONCTION QUI FREE UN TABLEAU DE CARACTERES */
/* */
/* prend en argument un tableau de caracteres */
/* */
/* renvoie rien */
void	freetab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
		free(tab[i++]);
}

/* FONCTION QUI FREE ET TERMINE LE PROGRAMME */
/* */
/* prend en argument la structure t_minijoker */
/* prend en argument le dernier input de l'utilisateur a free */
/* */
/* renvoie rien */
void	exit_minijoker(t_minijoker *mini, char *str)
{
	freetab(mini->env_copy);
	free(mini->env_copy);
	if (mini->tokens)
		mini_tokenclear(mini->tokens);
	free(str);
	rl_clear_history();
	//system("leaks minijoker");
	exit(EXIT_SUCCESS);
}
