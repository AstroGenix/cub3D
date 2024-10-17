/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <dberehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:07:31 by dberehov          #+#    #+#             */
/*   Updated: 2024/10/17 23:09:43 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// s - Prints a string
t_format	print_str(char *c, t_format *spec)
{
	int	i;

	if (c == 0)
		spec->bt_length += write(1, "(null)", 6);
	if (c == 0)
		return (*spec);
	i = 0;
	while (c[i])
	{
		spec->bt_length += write (1, &c[i], 1);
		i++;
	}
	return (*spec);
}

// c - Prints a single char
t_format	print_chr(int c, t_format *spec)
{
	spec->bt_length += write (1, &c, 1);
	return (*spec);
}
