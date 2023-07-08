/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_tokenfirst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:42:47 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/07 12:54:09 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"
#include <stdio.h>
t_token *mini_tokenfirst(t_token *lst)
{
	while (lst)
	{
		if (!lst->prev)
			return (lst);
		lst = lst->prev;
	}
	return (lst);
}
