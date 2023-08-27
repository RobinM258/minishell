/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:36:25 by iqiyu             #+#    #+#             */
/*   Updated: 2023/07/22 15:51:27 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

int	mini_tlen(char **sep, t_token *tokens)
{
	int	size;

	size = 0;
	while (tokens)
	{
		if (mini_is_intab(sep, tokens->content, 1) && tokens->content[0] != '|')
			tokens = tokens->next->next;
		if (!tokens || (mini_is_intab(sep, tokens->content, 1)
				&& tokens->content[0] == '|'))
			break ;
		if (!mini_is_intab(sep, tokens->content, 1))
		{
			size++;
			tokens = tokens->next;
		}
	}
	return (size);
}

char	**mini_link(char **sep, t_token *tokens)
{
	char	**arg;
	int		i;

	i = 0;
	arg = (char **)malloc(sizeof(char *) * (mini_tlen(sep, tokens) + 1));
	while (tokens)
	{
		if (mini_is_intab(sep, tokens->content, 1) && tokens->content[0] != '|')
			tokens = tokens->next->next;
		if (!tokens || (mini_is_intab(sep, tokens->content, 1)
				&& tokens->content[0] == '|'))
			break ;
		if (!mini_is_intab(sep, tokens->content, 1))
		{
			arg[i++] = tokens->content;
			tokens = tokens->next;
		}
	}
	arg[i] = NULL;
	return (arg);
}

int	exec_loop(t_minijoker *mini)
{
	mini_exec(mini);
	if (mini->error == UNKNOW_COMMAND)
		mini->error = true_exec(mini, 0);
	while (mini->tokens && mini->error == UNKNOW_COMMAND)
	{
		if (!is_mini_func(mini->tokens->content))
			mini->error = true_exec(mini, 0);
		mini->tokens = mini->tokens->next;
	}
	return (mini->error);
}

int	true_exec(t_minijoker *mini, int i)
{
	pid_t	pid;
	char	**path;
	char	*str;
	int		status;
	char	**args;

	i = 0;
	pid = fork();
	if (pid < 0)
		return (FORK_ERROR);
	if (pid == 0)
	{
		path = mini_ft_split(get_env(mini, "PATH"), ':');
		i = 0;
		while (path[i])
		{
			str = mini_append_path(path[i], mini->tokens->content);
			if (access(str, X_OK) == 0)
			{
				args = mini_link(mini->sep, mini->tokens);
				execve(str, args, NULL);
			}
			free(str);
			i++;
		}
		if (!mini->tokens->content)
			return (ARG_NUMBER);
		printf("%s: command not found\n", mini->tokens->content);
		exit(UNKNOW_COMMAND);
	}
	wait(&status);
	return (status);
}
