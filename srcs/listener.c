/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listener.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:23:21 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/08 14:25:36 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

/* FONCTION BOUCLE INFINI QUI LIT LES INPUT DE L'UTILISATEUR */
/* */
/* prend en argument t_minijoker */
/* */
/* renvoie rien */
void	listen(t_minijoker *mini)
{
	char	*str;
	int		error;

	while (1)
	{
		str = readline(PROMPT);
		error = parser(mini, str);
		if (error == END)
			exit_minijoker(mini, str);
		if (error != QUOTE_ERROR)
			exec_loop(mini);
		add_history(str);
		free(str);
		mini_tokenclear(mini->tokens);
	}
}
