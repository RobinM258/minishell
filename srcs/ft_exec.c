/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:23:12 by iqiyu             #+#    #+#             */
/*   Updated: 2023/07/01 17:55:41 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

int is_ft_func(t_miniJoker *mini, int i)
{
	if (ft_strcmp(mini->tokens[i], "echo", 0) == 0)
		return (1);
	if (ft_strcmp(mini->tokens[i], "cd", 0) == 0)
		return (1);
	if (ft_strcmp(mini->tokens[i], "pwd", 0) == 0)
		return (1);
	if (ft_strcmp(mini->tokens[i], "env", 0) == 0)
		return (1);
	if (ft_strcmp(mini->tokens[i], "export", 0) == 0)
		return (1);
	if (ft_strcmp(mini->tokens[i], "unset", 0) == 0)
		return (1);
	return (0);
}

int	exec_ft(t_miniJoker *mini)
{
	int	error;

	error = 1;
	if (ft_strcmp(mini->tokens[0], "echo", 0) == 0)
		error = ft_echo(mini);
	if (ft_strcmp(mini->tokens[0], "env", 0) == 0)
		error = ft_env(mini);
	if (ft_strcmp(mini->tokens[0], "export", 0) == 0)
		error = ft_export(mini, 1);
	if (ft_strcmp(mini->tokens[0], "unset", 0) == 0)
		error = ft_unset(mini, 1);
	return (error);
}
