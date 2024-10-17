/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <dberehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:18:21 by dberehov          #+#    #+#             */
/*   Updated: 2024/10/17 23:10:35 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new_string;
	int		length_s1;
	int		i;

	if (!s1)
		return (NULL);
	length_s1 = ft_strlen(s1);
	new_string = malloc(sizeof(char) * (length_s1 + ft_strlen(s2) + 1));
	if (!new_string)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		new_string[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		new_string[length_s1] = s2[i];
		i++;
		length_s1++;
	}
	new_string[length_s1] = '\0';
	return (new_string);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*string_find;

	string_find = (unsigned char *) s;
	while (*string_find != '\0')
	{
		if (*string_find == c)
			return ((char *) string_find);
		string_find++;
	}
	if (c == 0)
		return ((char *)string_find);
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	bzero(ptr, nmemb * size);
	return (ptr);
}
