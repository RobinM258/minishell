/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:23:12 by iqiyu             #+#    #+#             */
/*   Updated: 2023/07/08 14:07:10 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

/* (WIP) FONCTION QUI VERIFIE SI LA CHAINE DEMANDE EST UN BUILTIN */
/* */
/* prend en argument t_minijoker qui a le tableau des tokens */
/* prend en argument un int qui correspond a l index de la chaine cherche */
/* */
/* renvoie 1 si la fonction est un builtin 0 sinon */
int	is_mini_func(t_minijoker *mini)
{
	if (mini_strcmp(mini->tokens->content, "echo", 0) == 0)
		return (1);
	if (mini_strcmp(mini->tokens->content, "cd", 0) == 0)
		return (1);
	if (mini_strcmp(mini->tokens->content, "pwd", 0) == 0)
		return (1);
	if (mini_strcmp(mini->tokens->content, "env", 0) == 0)
		return (1);
	if (mini_strcmp(mini->tokens->content, "export", 0) == 0)
		return (1);
	if (mini_strcmp(mini->tokens->content, "unset", 0) == 0)
		return (1);
	return (0);
}

/* (WIP) FONCTION QUI EXECUTE LES FONCTIONS BUILTIN */
/* */
/* prend en arguments les tokens /!\ CA NE GERE QUE LA PREMIERE COMMANDE /!\ */
/* */
/* renvoie -1 si aucune commande n'est execute */
int	mini_exec(t_minijoker *mini)
{
	int	error;

	error = UNKNOW_COMMAND;
	if (mini_strcmp(mini->tokens->content, "echo", 0) == 0)
		error = mini_echo(mini);
	else if (mini_strcmp(mini->tokens->content, "cd", 0) == 0)
		error = mini_cd(mini);
	else if (mini_strcmp(mini->tokens->content, "unset", 0) == 0)
		error = mini_unset(mini);
	else if (mini_strcmp(mini->tokens->content, "export", 0) == 0)
		error = mini_export(mini);
	else if (mini_strcmp(mini->tokens->content, "env", 0) == 0)
		error = mini_env(mini);
	else if (mini_strcmp(mini->tokens->content, "pwd", 0) == 0)
		error = mini_pwd();
	return (error);
}
