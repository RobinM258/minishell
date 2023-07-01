/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:53:42 by iqiyu             #+#    #+#             */
/*   Updated: 2023/07/01 17:32:15 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

void    free_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
        free(tab[i++]);
    free(tab);
}

void    exit_miniJoker(t_miniJoker *mini, char *str)
{
    free_tab(mini->env_copy);
    free_tab(mini->tokens);
    free(str);
    rl_clear_history();
    system("leaks miniJoker");
    exit(EXIT_SUCCESS);
}
