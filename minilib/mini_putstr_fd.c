/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_putstr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:03:38 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/22 15:32:33 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

void	mini_putstr_fd(int fd, char *str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		write(fd, &str[i++], 1);
}
