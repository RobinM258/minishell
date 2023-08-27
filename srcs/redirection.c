/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:35:37 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/22 15:44:35 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

void	here_doc(t_minijoker *mini)
{
	int		fd;
	char	*del;
	char	*input;

	del = mini->tokens->content;
	fd = open(".heredoc", O_RDWR | O_CREAT | O_TRUNC, 0777);
	input = readline("> ");
	while (mini_strcmp(input, del, 0) != 0)
	{
		write(fd, input, mini_strlen(input));
		write(fd, "\n", 1);
		free(input);
		input = readline("> ");
	}
	free(input);
	close(fd);
	mini->redir_fd = open(".heredoc", O_RDONLY, 0777);
	mini->fdin = dup2(mini->redir_fd, 0);
	mini_tokendelone(&mini->tokens->prev);
	mini_tokendelone(&mini->tokens);
	return ;
}

void	open_redirection(t_minijoker *mini)
{
	int	fd;
	int	flag;

	if (mini_strcmp(mini->tokens->prev->content, "<", 0) == 0)
		flag = O_RDONLY;
	if (mini_strcmp(mini->tokens->prev->content, ">", 0) == 0)
		flag = O_WRONLY | O_CREAT | O_TRUNC;
	if (mini_strcmp(mini->tokens->prev->content, ">>", 0) == 0)
		flag = O_WRONLY | O_CREAT | O_APPEND;
	else
	{
		here_doc(mini);
		return ;
	}
	if (mini->redir_fd != -1)
		fd = mini->redir_fd;
	mini->redir_fd = open(mini->tokens->content, flag, 0777);
	if (mini->redir_fd == -1)
	{
		mini->error = OPEN_ERROR;
		perror(mini->tokens->content);
		return ;
	}
	if (mini_strcmp(mini->tokens->prev->content, "<", 0) == 0)
		mini->fdin = dup2(mini->redir_fd, 0);
	else if (mini_strcmp(mini->tokens->prev->content, "<<", 0) != 0)
		mini->fdout = dup2(mini->redir_fd, 1);
	close(fd);
	mini_tokendelone(&mini->tokens->prev);
	mini_tokendelone(&mini->tokens);
}
/*
int redirection(t_minijoker *mini)
{
	pid_t   pid;
	int     statut;
	int     mini->error;

	mini->error = SUCCESS;
	pid = fork();
	if (pid == -1)
		return (FORK_mini->error);
	if (pid == 0)
	{
		while (mini->tokens->next)
		{
			if (mini_is_intab(mini->sep, mini->tokens->content))
			{
				mini->tokens = mini->tokens->next;
				if (!mini->tokens)
				{
					mini->error = FILE_NOT_FOUND;
					break ;
				}
				mini->error = open_redirection(mini);
				if (mini->error != SUCCESS)
					break ;
			}
			else
				mini->tokens = mini->tokens->next;
		}
		if (!mini->error)
		{
			mini->tokens = mini_tokenfirst(mini->tokens);
			mini->error = exec_loop(mini);
		}
		exit(mini->error);
	}
	wait(&statut);
	return (WEXITSTATUS(statut));
}*/

void	redirection(t_minijoker *mini)
{
	mini->save_stdout = dup(STDOUT_FILENO);
	mini->save_stdin = dup(STDIN_FILENO);
	while (mini->tokens->next)
	{
		if (mini_is_intab(mini->sep, mini->tokens->content, 1)
			&& mini_strcmp(mini->tokens->content, "|", 0) != 0)
		{
			mini->tokens = mini->tokens->next;
			if (!mini->tokens)
			{
				mini->error = INPUT_ERROR;
				mini_putstr_fd(2,
					"syntax error near unexpected token `newline'\n");
				break ;
			}
			open_redirection(mini);
			if (mini->error != SUCCESS)
				break ;
		}
		else
			mini->tokens = mini->tokens->next;
	}
	if (!mini->error)
	{
		mini->tokens = mini_tokenfirst(mini->tokens);
		if (mini_tokenfind(mini->tokens, '|', 1))
			mini_pipe(mini);
		else
			exec_loop(mini);
	}
	dup2(mini->save_stdout, STDOUT_FILENO);
	dup2(mini->save_stdin, STDIN_FILENO);
	close(mini->save_stdout);
	close(mini->save_stdin);
	if (mini->redir_fd != -1)
		close(mini->redir_fd);
}
