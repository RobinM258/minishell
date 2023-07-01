/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:35:56 by romartin          #+#    #+#             */
/*   Updated: 2023/06/30 17:56:14 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

int ft_env(t_miniJoker *mini)
{
	int i;

	i = 0;
	while (mini->env_copy[i])
	{
		printf("%s\n", mini->env_copy[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}