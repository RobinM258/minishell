/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:50:26 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/22 15:45:43 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

void	mini_cd(t_minijoker *mini)
{
	char	*path;
	char	*exec;

	mini->error = SUCCESS;
	mini->tokens = mini->tokens->next;
	if (!mini->tokens
		|| mini_strcmp(mini->tokens->content, "~", 0) == 0)
		chdir(get_env(mini, "HOME"));
	else if (chdir(mini->tokens->content) == -1)
	{
		path = getcwd(NULL, 0);
		exec = mini_append_path(path, mini->tokens->content);
		free(path);
		if (access(exec, X_OK) == 0)
		{
			mini->error = EXEC_FILE;
			mini_putstr_fd(2, "cd: ");
			perror(mini->tokens->content);
		}
		else
		{
			mini->error = DIR_NOT_FOUND;
			mini_putstr_fd(2, "cd: ");
			perror(mini->tokens->content);
		}
		free(exec);
	}
}
