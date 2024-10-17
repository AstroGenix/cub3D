/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:50:05 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/09 23:50:06 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>

static size_t	word_stop(char const *str, char stop)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != stop)
		i++;
	return (i);
}

static int	word_count(char const *str, char c)
{
	size_t	i;
	size_t	len;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		len = word_stop(str + i, c);
		i += len;
		if (len > 0)
			count++;
	}
	return (count);
}

static void	*free_word(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		num;

	if (!s)
		return (NULL);
	i = 0;
	j = -1;
	num = word_count(s, c);
	str = (char **)malloc(sizeof(char *) * (num + 1));
	if (!str)
		return (NULL);
	while (++j < num)
	{
		while (s[i] == c)
			i++;
		str[j] = ft_substr(s, i, word_stop(s + i, c));
		if (!str[j])
			return (free_word(str));
		i += word_stop(s + i, c);
	}
	str[num] = NULL;
	return (str);
}

/* 04
- - Description
Allocates (with malloc(3)) and returns an array of strings obtained by
splitting ’s’ using the character ’c’ as a delimiter. The array must end
with a NULL pointer.
- - Parameters
s: The string to be split.
c: The delimiter character.
- - Return
The array of new strings resulting from the split.
NULL if the allocation fails.
*/

/*
int main()
{
    char *str = "AXBBXCCCXDDXE";
    char **array = ft_split(str, 'X');
    printf("START\n");
    for (int i = 0; i < 5; ++i)
    {
	    printf(":%s:\n",array[i]);
    }
    printf("END");
}
*/