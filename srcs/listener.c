/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listener.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:23:21 by dgoubin           #+#    #+#             */
/*   Updated: 2023/06/27 15:36:00 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

void    listen(t_miniJoker *mini)
{
    char    *str;
    int     end;

    end = 0;
    while (1)
    {
        str = readline("miniJoker> ");
        end = parser(mini, str);
        if (end)
            exit_miniJoker(mini, str);
        add_history(str);
        exec_loop(str, mini);
        free(str);
        freetab(mini->tokens);
    }
}
