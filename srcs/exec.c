/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:36:25 by iqiyu             #+#    #+#             */
/*   Updated: 2023/09/11 20:43:00 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

static int	mini_tlen(char **sep, t_token *tokens)
{
	int	size;

	size = 0;
	while (tokens)
	{
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

static char	**mini_link(char **sep, t_token *tokens)
{
	char	**arg;
	int		i;

	i = 0;
	arg = (char **)malloc(sizeof(char *) * (mini_tlen(sep, tokens) + 1));
	while (tokens)
	{
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

static void	check_path(t_minijoker *mini)
{
	if (get_env(mini, "PATH") == NULL
		|| mini_strcmp(get_env(mini, "PATH"), "", 0) == 0)
	{
		printf("%s: No such file or directory\n", mini->tokens->content);
		exit(UNKNOW_COMMAND);
	}
}

static void	exec_fils(t_minijoker *mini, int i, char *str)
{
	char	**args;
	char	**path;

	if (access(mini->tokens->content, X_OK) == 0)
	{
		args = mini_link(mini->sep, mini->tokens);
		execve(mini->tokens->content, args, NULL);
	}
	check_path(mini);
	path = mini_ft_split(get_env(mini, "PATH"), ':');
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
	mini_putstr_fd(2, "miniJoker: ");
	mini_putstr_fd(2, mini->tokens->content);
	mini_putstr_fd(2, ": command not found\n");
	exit(UNKNOW_COMMAND);
}

int	true_exec(t_minijoker *mini)
{
	pid_t	pid;
	int		i;
	int		status;
	char	*str;

	i = 0;
	str = NULL;
	pid = fork();
	if (pid < 0)
		return (FORK_ERROR);
	if (pid == 0)
		exec_fils(mini, i, str);
	wait(&status);
	if (status == 0)
		return (0);
	if (!mini->tokens->content)
		return (ARG_NUMBER);
	return (status);
}
