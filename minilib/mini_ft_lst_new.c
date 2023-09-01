/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_ft_lst_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:12:03 by dgoubin           #+#    #+#             */
/*   Updated: 2023/08/31 13:14:09 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

t_env	*mini_ft_lst_new(char *var, char *val)
{
	t_env	*tmp;

	tmp = malloc(sizeof(t_env));
	if (!tmp)
		exit(EXIT_FAILURE);
	tmp->val = val;
	tmp->var = var;
	tmp->next = NULL;
	return (tmp);
}
