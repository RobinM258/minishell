/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:23:12 by iqiyu             #+#    #+#             */
/*   Updated: 2023/08/25 21:41:20 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

/* (WIP) FONCTION QUI EXECUTE LES FONCTIONS BUILTIN */
/* */
/* prend en arguments les tokens /!\ CA NE GERE QUE LA PREMIERE COMMANDE /!\ */
/* */
/* renvoie -1 si aucune commande n'est execute */
void	mini_exec(t_minijoker *mini)
{
	mini->error = UNKNOW_COMMAND;
	if (mini_strcmp(mini->tokens->content, "echo", 0) == 0)
		mini->error = mini_echo(mini);
	else if (mini_strcmp(mini->tokens->content, "cd", 0) == 0)
		mini_cd(mini);
	else if (mini_strcmp(mini->tokens->content, "unset", 0) == 0)
		mini_unset(mini);
	else if (mini_strcmp(mini->tokens->content, "export", 0) == 0)
		mini_export(mini);
	else if (mini_strcmp(mini->tokens->content, "env", 0) == 0)
		mini->error = mini_env(mini);
}
