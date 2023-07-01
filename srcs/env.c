/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:21:06 by iqiyu             #+#    #+#             */
/*   Updated: 2023/07/01 17:35:09 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

char    *getEnv(t_miniJoker *mini, char *str)
{
    int i;
    char *a;

    i = 0;
    while (mini->env_copy[i])
    {
        a = ft_cut_to(mini->env_copy[i++], '=');
        if (ft_strcmp(a , str, 0) == 0)
            return (&mini->env_copy[i - 1][ft_charfind(mini->env_copy[i - 1], '=') + 1]);
        free(a);
    }
    return (NULL);
}
