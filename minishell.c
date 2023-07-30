/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:10:25 by emohamed          #+#    #+#             */
/*   Updated: 2023/07/30 19:31:40 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int main()
{
    char *input;
    char **str;
    while(1)
    {
        int i = 0;
        display_prompt();
        input = read_input();
        str = split_input(input);
        int j = count_s_lenght(input, ' ');
        
    while (i < j)
    {
        printf("%s\n", str[i]);
        i++;   
    }
    
    }
    return 0;
}