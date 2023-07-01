/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:46:01 by dgoubin           #+#    #+#             */
/*   Updated: 2023/06/19 15:46:15 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

void	sigint(int code)
{
	(void)code;
	write(1, "\n", 1);
    rl_on_new_line();
	rl_replace_line("", 0);
    rl_redisplay();
	return ;
}