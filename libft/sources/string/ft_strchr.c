/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:10:28 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/02 15:10:29 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	chr;

	chr = (char)c;
	while (*s != '\0' && *s != chr)
		s++;
	if (*s == chr)
		return ((char *)s);
	return (0);
}

/*
- - Description
The strchr() function returns a pointer to the first occurrence of the
character c in the string s.
*/

/*
int main(void)
{
	char string[] = "To be, or not to be, that is the question.";
	char *first_L1 = strchr(string, 'h');
	printf("strchr - %s\n", first_L1);
	char *first_L2 = ft_strchr(string, 'h');
	printf("ft_strchr - %s\n", first_L2);
}
*/
