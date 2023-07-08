/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:15:17 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/07 14:52:55 by dgoubin          ###   ########.fr       */
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
	mini.fdin = 1;
	mini.fdout = 0;
	mini.sep[0] = "|";
	mini.sep[1] = "<<";
	mini.sep[2] = ">>";
	mini.sep[3] = "<";
	mini.sep[4] = ">";
	mini.sep[5] = NULL;
	printf("\x1b[31m   .    .    \x1b[30m__________   \x1b[31m__   __\n  /  \\ / \\  \x1b[30m|   _______| \x1b[31m|  | |  |\n / /\\__/\\ \\ \x1b[30m|  |_______  \x1b[31m|  |_|  |\n/_/      \\_\\\x1b[30m|_________ | \x1b[31m|   _   |\n\x1b[30m_______________________| \x1b[31m|__| |__|\x1b[0m\n\n");
	signal(SIGINT, &sigint);
	listen(&mini);
	return (SUCCESS);
}

/*
   .    . 	  __________   __   __ \n
  /	 \/  \   |   _______| |  | |  |\n
 / /\__/\ \	 |  |_______  |  |_|  |\n
/_/	     \_\ |_________ | |   _   |\n
________________________| |__| |__|\n
*/