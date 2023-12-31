/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_tokenwrite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:11:45 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/22 15:51:16 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"
#include <stdio.h>

void	mini_tokenwrite(t_token *lst)
{
	while (lst)
	{
		if (lst->content)
			printf("-%s-\n", lst->content);
		lst = lst->next;
	}
}
