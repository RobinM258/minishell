/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:36:25 by iqiyu             #+#    #+#             */
/*   Updated: 2023/07/08 17:12:09 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

int	mini_tlen(char **sep, t_token *tokens)
{
	int	size;

	size = 0;
	while (tokens)
	{
		if (mini_is_intab(sep, tokens->content))
			tokens = tokens->next->next;
		if (!tokens)
			break;
		if (!mini_is_intab(sep, tokens->content)){
		size++;
		tokens = tokens->next;
		}
	}
	return (size);
}

char **mini_link(char **sep, t_token *tokens)
{
  	char **arg = (char **)malloc(sizeof(char *) * (mini_tlen(sep, tokens) + 1));
  	int i = 0;
  	while (tokens)
  	{
		if (mini_is_intab(sep, tokens->content))
			tokens = tokens->next->next;
		if (!tokens)
			break;
		if (!mini_is_intab(sep, tokens->content))
		{arg[i++] = tokens->content;
		tokens = tokens->next;}
	}
	arg[i] = NULL;
	return (arg);
}

int	exec_loop(t_minijoker *mini)
{
	int	error;

	error = mini_exec(mini);
	if (error == UNKNOW_COMMAND)
		error = true_exec(mini);
	while (mini->tokens && error == UNKNOW_COMMAND)
	{
		if (!is_mini_func(mini))
			error = true_exec(mini);
		mini->tokens = mini->tokens->next;
	}
	//error_manager(error);
	return (error);
}

int	true_exec(t_minijoker *mini)
{
	pid_t pid;
	int i;
	char **argv;
	char *str;
	char *tmp;
	int status;
	char **arg;

	i = 0;
	pid = fork();
	if (pid < 0)
		return (FORK_ERROR);
	if (pid == 0)
	{
		argv = mini_ft_split(get_env(mini, "PATH"), ':');
		i = 0;
		while (argv[i])
		{
			tmp = mini_strjoin(argv[i], "/");
			str = mini_strjoin(tmp, mini->tokens->content);
			free(tmp);
			if (access(str, X_OK) == 0)
			{
				arg = mini_link(mini->sep, mini->tokens);
				execve(str, arg, NULL);
				free(arg);
				break ;
			}
			i++;
		}
		if (!mini->tokens->content)
			return (ARG_NUMBER);
		printf("%s: command not found\n", mini->tokens->content);
	}
	wait(&status);
	return (SUCCESS);
}
