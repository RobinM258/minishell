/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:34:13 by dgoubin           #+#    #+#             */
/*   Updated: 2023/06/27 15:15:53 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

int    parser(t_miniJoker *mini, char *input)
{
  int     ret;

  if (!input)
    return (1);
  ret = 0;
  mini->tokens = minisplit(input, mini->sep);
  if (ft_strcmp(mini->tokens[0], "exit", 0) == 0)
    ret = 1;
  return (ret);
}