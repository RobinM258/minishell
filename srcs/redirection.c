/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:35:37 by dgoubin           #+#    #+#             */
/*   Updated: 2023/09/11 20:43:25 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

void	here_doc(t_minijoker *mini, int fd)
{
	char	*del;
	char	*input;

	del = mini->tokens->content;
	fd = open(".heredoc", O_RDWR | O_CREAT | O_TRUNC, 0777);
	input = readline("> ");
	while (mini_strcmp(input, del, 0) != 0)
	{
		if (!input)
		{
			mini->error = 1;
			return ;
		}
		write(fd, input, mini_strlen(input));
		write(fd, "\n", 1);
		free(input);
		input = readline("> ");
	}
	free(input);
	close(fd);
	mini->redir_fd = open(".heredoc", O_RDONLY, 0777);
	mini->fdin = dup2(mini->redir_fd, 0);
	mini->tokens = mini->tokens->prev;
	mini_tokendelone(&mini->tokens);
	mini_tokendelone(&mini->tokens);
}

static void	open_redirection_bis(t_minijoker *mini, int flag)
{
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
	mini->tokens = mini->tokens->prev;
	mini_tokendelone(&mini->tokens);
	mini_tokendelone(&mini->tokens);
}

void	open_redirection(t_minijoker *mini)
{
	int			flag;

	flag = 0;
	if (mini_strcmp(mini->tokens->prev->content, "<", 0) == 0)
		flag = O_RDONLY;
	else if (mini_strcmp(mini->tokens->prev->content, ">", 0) == 0)
		flag = O_WRONLY | O_CREAT | O_TRUNC;
	else if (mini_strcmp(mini->tokens->prev->content, ">>", 0) == 0)
		flag = O_WRONLY | O_CREAT | O_APPEND;
	else if (mini_strcmp(mini->tokens->prev->content, "<<", 0) == 0)
	{
		here_doc(mini, 0);
		return ;
	}
	else
		return ;
	if (mini->redir_fd != -1)
		close(mini->redir_fd);
	open_redirection_bis(mini, flag);
}

static void	open_redirection_boucle(t_minijoker *mini)
{
	while (mini->tokens && mini->tokens->next)
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
			if (mini->error != 0)
				break ;
		}
		else
			mini->tokens = mini->tokens->next;
	}
	mini->tokens = mini_tokenfirst(mini->tokens);
}

void	redirection(t_minijoker *mini)
{
	mini->save_stdout = dup(STDOUT_FILENO);
	mini->save_stdin = dup(STDIN_FILENO);
	open_redirection_boucle(mini);
	if (!mini->error)
	{
		mini->tokens = mini_tokenfirst(mini->tokens);
		mini->first = mini->tokens;
		if (mini_tokenfindchar(mini->tokens, '|', 1))
			mini_pipe(mini);
		else
		{
			mini_exec(mini);
			if (mini->error == UNKNOW_COMMAND)
				mini->error = true_exec(mini);
		}
	}
	dup2(mini->save_stdout, STDOUT_FILENO);
	dup2(mini->save_stdin, STDIN_FILENO);
	close(mini->save_stdout);
	close(mini->save_stdin);
	if (mini->redir_fd != -1)
		close(mini->redir_fd);
}
