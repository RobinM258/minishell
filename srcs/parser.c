/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:34:13 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/08 17:09:39 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

/* FONCTION QUI PARSE LES INPUT DE L'UTILISATEUR EN TOKENS */
/* */
/* prend en argument t_minijoker pour les tokens */
/* prend en argument une chaine de caractere qui est les input */
/*		de l'utilisateur */
/* renvoie 1 si le programme doit se fermer 0 sinon */
int	parser(t_minijoker *mini, char *input)
{
	if (!input)
	{
		mini->tokens = NULL;
		return (END);
	}
	mini->tokens = mini_split(input, mini->sep);
	if (!mini->tokens)
		return (QUOTE_ERROR);
	if (mini_strcmp(mini->tokens->content, "exit", 0) == 0)
		return (END);
	return (SUCCESS);
}
