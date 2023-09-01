/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_ft_lst_add_back.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:12:25 by dgoubin           #+#    #+#             */
/*   Updated: 2023/08/31 13:29:35 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

void	mini_ft_lst_add_back(t_env **lst, char *var, char *val)
{
	t_env	*new;

	new = mini_ft_lst_new(var, val);
	if (lst)
	{
		if (*lst)
			mini_ft_lst_last(*lst)->next = new;
		else
			*lst = new;
	}
}
