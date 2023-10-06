/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:00:32 by emohamed          #+#    #+#             */
/*   Updated: 2023/09/30 21:58:22 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	gvs(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (ft_isalpha(str[i])))
	{
		i++;
	}
	return (i);
}
