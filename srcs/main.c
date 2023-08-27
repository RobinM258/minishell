/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:15:17 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/31 15:30:57 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

/* /!\ W.I.P /!\ */
int	main(int ac, char *av[], char **env)
{
	int			i;
	t_minijoker	mini;

	(void)av;
	if (ac != 1)
	{
		write(2, "Bad arg number\n", 15);
		exit(ARG_NUMBER);
	}
	mini.env_copy = (char **)malloc(sizeof(char *) * (mini_tablen(env) + 1));
	if (!mini.env_copy)
		return (MALLOC_ERROR);
	i = -1;
	while (env[++i])
		mini.env_copy[i] = mini_strdup(env[i]);
	mini.env_copy[i] = NULL;
	mini.fdin = 0;
	mini.fdout = 1;
	mini.sep[0] = "|";
	mini.sep[1] = "<<";
	mini.sep[2] = ">>";
	mini.sep[3] = "<";
	mini.sep[4] = ">";
	mini.sep[5] = NULL;
	mini.error = SUCCESS;
	mini.tokens = NULL;
	printf("\x1b[37m          \x1b[30m__  __     _               _      ");
	printf("\x1b[31m   _            _                     \x1b[0m\n");
	printf("\x1b[37m    o O O\x1b[30m|  \\/  |   (_)    _ _      (_)    ");
	printf("\x1b[31m _ | |   ___    | |__    ___      _ _  \x1b[0m\n");
	printf("\x1b[37m   o     \x1b[30m| |\\/| |   | |   | ' \\     | |  \x1b[31m");
	printf("  | || |  / _ \\   | / /   / -_)    | '_|\x1b[0m\n");
	printf("\x1b[37m  TS__[O]\x1b[30m|_|__|_|  _|_|_  |_||_|   _|_|_   ");
	printf("\x1b[31m_\\__/   \\___/   |_\\_\\   \\___|   _|_|_  \x1b[0m\n");
	printf("\x1b[37m {======|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"");
	printf("\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"| \x1b[0m\n");
	printf("\x1b[37m./o--000'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"");
	printf("`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\x1b[0m\n");
	signal(SIGINT, &sigint);
	signal(SIGQUIT, SIG_IGN);
	listen(&mini);
	return (SUCCESS);
}
