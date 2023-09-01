/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_ft_lst_last.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:11:41 by dgoubin           #+#    #+#             */
/*   Updated: 2023/08/31 13:14:04 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

t_env	*mini_ft_lst_last(t_env *env)
{
	while (env->next)
	{
		if (env->next == NULL)
			return (env);
		env = env->next;
	}
	return (env);
}
