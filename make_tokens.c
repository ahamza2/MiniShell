/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 08:46:46 by emohamed          #+#    #+#             */
/*   Updated: 2023/09/08 12:36:44 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.c"  


#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	count_s_lenght(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			j++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (j);
}

char	*allocat_s(const char *s, char c)
{
	int		i;
	int		len;
	char	*p;

	i = 0;
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	p = malloc(sizeof(char) * len + 1);
	if (!p)
		return (NULL);
	while (i < len)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	**ft_split(char  *s, char c)
{
	char	**p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	p = malloc(sizeof(char *) * count_s_lenght(s, c) + 1);
	if (!p)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			p[j] = allocat_s(&s[i], c);
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	p[j] = NULL;
	return (p);
}
void make_token(char *s, int *quotestate) 
{
    int i = 0;
    int insg = 0;
    int indb = 0;

    while (s[i]) 
    {
        if ((s[i] == '\'' && !indb))
        {
            s[i] = 16;
            insg = !insg;
        } 
        else if ((s[i] == '"' && !insg) )
        {  
                
            s[i] = 16;
            indb = !indb;
        }
        else if (!insg && !indb && s[i] == ' ') 
            s[i] = 16;
        i++;
    }
    if (insg || indb) 
        *quotestate = 1;
     else 
        *quotestate = 0;
}




int main() 
{
    int i  = 0;
    char input[] = "echo 'hello     \"$world\"'  '|' echo \"file.txt\" > amine.txt";
    int quoteState = 0; 

    make_token(input, &quoteState);
    char **str = ft_split(input, 16);    

    while(str[i])
    {
        printf("TOKEN : %s\n", str[i]);
        printf("Quote %d\n", quoteState);
        printf("--------------------\n");
        i++;
    }

    return 0;
}

