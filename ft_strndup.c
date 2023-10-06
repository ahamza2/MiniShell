/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:59:59 by emohamed          #+#    #+#             */
/*   Updated: 2023/10/01 09:45:15 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strndup(char const *str, size_t i)
{
	size_t	index;
	char	*dst;

	index = 0;
	dst = malloc_(sizeof(char) * (i + 1), NULL, 0, NULL);
	if (!dst)
		return (0);
	while (str[index] && index < i)
	{
		dst[index] = str[index];
		index++;
	}
	dst[index] = '\0';
	return (dst);
}
