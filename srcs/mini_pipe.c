/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:29:23 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/22 15:41:43 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

int	mini_pipe(t_minijoker *mini)
{
	int		pipefd[2];
	pid_t	pid;
	int		status;

	if (pipe(pipefd) == -1)
		return (SUCCESS);
	pid = fork();
	if (pid < 0)
		return (SUCCESS);
	if (pid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		exec_loop(mini);
		exit(SUCCESS);
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		while (mini->tokens)
		{
			if (mini_strcmp(mini->tokens->content, "|", 0) == 0)
			{
				mini->tokens = mini->tokens->next;
				break ;
			}
			if (mini->tokens)
				mini->tokens = mini->tokens->next;
		}
		if (mini_tokenfind(mini->tokens, '|', 1))
			mini_pipe(mini);
		else if (mini->tokens)
			exec_loop(mini);
	}
	wait(&status);
	return (SUCCESS);
}
