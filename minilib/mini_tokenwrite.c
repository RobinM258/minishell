/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_tokenwrite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:11:45 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/08 17:02:58 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"
#include <stdio.h>

void    mini_tokenwrite(t_token *lst)
{
    while (lst)
    {
        if (lst->content)
            printf("-%s-\n", lst->content);
        lst = lst->next;
    }
}
