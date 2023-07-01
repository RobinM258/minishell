/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:15:17 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/01 16:31:07 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

int main(int ac, char *av[], char **env)
{
    (void)av;
    int         i;
    t_miniJoker mini;

    if (ac != 1)
    {
        write(2, "Bad arg number\n", 15);
        exit(EXIT_FAILLURE);
    }
    i = 0;
    while(env[i++])
        ;
    mini.env_copy = (char **)malloc(sizeof(char *) * i);
    if (!mini.env_copy)
        return (EXIT_FAILLURE);
    i = -1;
    while(env[++i])
        mini.env_copy[i] = ft_strdup(env[i]);
    mini.env_copy[i] = NULL;
    mini.sep[0] = "|";
    mini.sep[1] = "<";
    mini.sep[2] = ">";
    mini.sep[3] = " ";
    mini.sep[4] = "<<";
    mini.sep[5] = ">>";
    mini.sep[6] = NULL;
	printf("\x1b[31m   .    .    \x1b[32m__________   \x1b[31m__   __\n  /  \\ / \\  \x1b[32m|   _______| \x1b[31m|  | |  |\n / /\\__/\\ \\ \x1b[32m|  |_______  \x1b[31m|  |_|  |\n/_/      \\_\\\x1b[32m|_________ | \x1b[31m|   _   |\n\x1b[32m_______________________| \x1b[31m|__| |__|\x1b[0m\n\n");
    signal(SIGINT, &sigint);
	listen(&mini);
    return (EXIT_SUCCESS);
}

/*
   .    . 	  __________   __   __ \n
  /	 \/  \   |   _______| |  | |  |\n
 / /\__/\ \	 |  |_______  |  |_|  |\n
/_/	     \_\ |_________ | |   _   |\n
________________________| |__| |__|\n
*/