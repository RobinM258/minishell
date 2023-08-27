/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_tokenadd_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 09:36:08 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/22 15:34:18 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

int	mini_tokenadd_back(t_token **lst, t_token *token)
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
