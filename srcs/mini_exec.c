/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:23:12 by iqiyu             #+#    #+#             */
/*   Updated: 2023/09/01 19:14:45 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

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
		mini->error = mini_export(mini, 0);
	else if (mini_strcmp(mini->tokens->content, "env", 0) == 0)
		mini->error = mini_env(mini, 0);
	else if (mini_strcmp(mini->tokens->content, "pwd", 0) == 0)
		mini->error = mini_pwd();
}
