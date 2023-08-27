/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_tokenclear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 09:20:55 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/22 15:34:33 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

void	mini_tokenclear(t_token *lst)
{
	t_token	*tmp;

	while (lst)
	{
		tmp = lst->next;
		if (lst->content)
			free(lst->content);
		free(lst);
		lst = tmp;
	}
}
