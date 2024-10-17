/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:10:45 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/02 15:10:46 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	chr;

	i = 0;
	chr = (char)c;
	while (str[i] != '\0')
		i++;
	while (i > 0 && str[i] != chr)
		i--;
	if (str[i] == chr)
		return ((char *)&str[i]);
	return (0);
}

/*
- - Description
The strrchr() function returns a pointer to the last occurrence of
the character c in the string s.
*/

/*
int main(void)
{
	char string[] = "Forty-two, the ultimate answer to life.";
	char *first_L1 = strrchr(string, '1');
	printf("strrchr - %s\n", first_L1);
	char *first_L2 = ft_strrchr(string, '1');
	printf("ft_strrchr - %s\n", first_L2);
}
*/
