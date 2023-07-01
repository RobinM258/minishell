/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:36:25 by iqiyu             #+#    #+#             */
/*   Updated: 2023/07/01 15:22:36 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

void    exec_loop(char *str, t_miniJoker *mini)
{
    int end;
    int n;

    n = 0;
    end = -1;
    (void)str;
    end = exec_ft(mini);
    if (end)
        end = true_exec(mini, n++);
    while (mini->tokens[n] && end)
    {
        if (!is_ft_func(mini, n))
            end = true_exec(mini, n++);
    }
}

int true_exec(t_miniJoker *mini, int i)
{
    if (!mini->tokens[i])
        return (1);
    printf("%s: command not found\n", mini->tokens[i]);
    return (0);
}
