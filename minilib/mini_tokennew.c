/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_tokennew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 09:41:11 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/07 13:18:55 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"
#include <stdio.h>
t_token *mini_tokennew(t_token *lst, char *str)
{
    t_token *token;

    token = NULL;
    if (str)
    {
        token = (t_token *)malloc(sizeof(t_token));
        if (!token)
            return NULL;
        token->content = str;
        if (lst)
            token->prev = mini_tokenlast(lst);
        else
            token->prev = NULL;
        token->next = NULL;
    }
    return (token);
}
