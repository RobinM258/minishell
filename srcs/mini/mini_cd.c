/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:50:26 by dgoubin           #+#    #+#             */
/*   Updated: 2023/09/10 15:17:11 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

static void	error(t_minijoker *mini, char *exec)
{
	if (access(exec, X_OK) == 0)
	{
		mini->error = 1;
		mini_putstr_fd(2, "cd: ");
		perror(mini->tokens->content);
	}
	else
	{
		mini->error = 1;
		mini_putstr_fd(2, "cd: ");
		perror(mini->tokens->content);
	}
}

void	mini_cd(t_minijoker *mini)
{
	char	*path;
	char	*exec;

	mini->error = 0;
	mini->tokens = mini->tokens->next;
	if (!mini->tokens
		|| mini_strcmp(mini->tokens->content, "~", 0) == 0)
	{
		if (get_env(mini, "HOME") == NULL)
			mini_putstr_fd(2, "cd: HOME not set\n");
		chdir(get_env(mini, "HOME"));
	}
	else if (chdir(mini->tokens->content) == -1)
	{
		path = getcwd(NULL, 0);
		exec = mini_append_path(path, mini->tokens->content);
		free(path);
		error(mini, exec);
		free(exec);
	}
}
