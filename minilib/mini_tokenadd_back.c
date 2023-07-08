/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_tokenadd_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 09:36:08 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/07 13:18:29 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"
#include <stdio.h>
int    mini_tokenadd_back(t_token **lst, t_token *token)
{
    if (!token)
        return (0);
    if (lst)
    {
        if (*lst)
        {
            token->prev = mini_tokenlast(*lst);
            mini_tokenlast(*lst)->next = token;
        }
        else
            *lst = token;
    }
    return (1);
}
