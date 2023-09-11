/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:15:17 by dgoubin           #+#    #+#             */
/*   Updated: 2023/09/10 16:05:11 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

void	print_train(void)
{
	printf("\x1b[37m          \x1b[38;2;100;100;100m__  ");
	printf("__     _               _      ");
	printf("\x1b[31m   _            _                     \x1b[0m\n");
	printf("\x1b[37m    o O O\x1b[38;2;100;100;100m|  \\/  |   (_)    _ _");
	printf("      (_)    ");
	printf("\x1b[31m _ | |   ___    | |__    ___      _ _  \x1b[0m\n");
	printf("\x1b[37m   o     \x1b[38;2;100;100;100m| |\\/| |   | |   | ' \\");
	printf("     | |  \x1b[31m");
	printf("  | || |  / _ \\   | / /   / -_)    | '_|\x1b[0m\n");
	printf("\x1b[37m  TS__[O]\x1b[38;2;100;100;100m|_|__|_|  ");
	printf("_|_|_  |_||_|   _|_|_   ");
	printf("\x1b[31m_\\__/   \\___/   |_\\_\\   \\___|   _|_|_  \x1b[0m\n");
	printf("\x1b[37m {======|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"");
	printf("\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"| \x1b[0m\n");
	printf("\x1b[37m./o--000'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"");
	printf("`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\x1b[0m\n");
}

void	mini_init(t_minijoker *mini, char *env[])
{
	int			i;

	mini->env_copy = (char **)malloc(sizeof(char *) * (mini_tablen(env) + 1));
	if (!mini->env_copy)
	{
		mini->error = MALLOC_ERROR;
		return ;
	}
	i = -1;
	while (env[++i])
		mini->env_copy[i] = mini_strdup(env[i]);
	mini->env_copy[i] = NULL;
	mini->fdin = 0;
	mini->fdout = 1;
	mini->end = 0;
	mini->sep[0] = "|";
	mini->sep[1] = "<<";
	mini->sep[2] = ">>";
	mini->sep[3] = "<";
	mini->sep[4] = ">";
	mini->sep[5] = NULL;
	mini->error = 0;
	mini->tokens = NULL;
}

int	main(int ac, char *av[], char **env)
{
	t_minijoker	mini;

	(void)av;
	rl_catch_signals = 0;
	mini.error = 0;
	if (ac != 1)
	{
		write(2, "Bad arg number\n", 15);
		exit(ARG_NUMBER);
	}
	mini_init(&mini, env);
	if (mini.error != 0)
		return (mini.error);
	print_train();
	signal(SIGINT, &sigint);
	signal(SIGQUIT, SIG_IGN);
	listen(&mini);
	return (0);
}
