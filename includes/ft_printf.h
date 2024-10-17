/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <dberehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:45:46 by dberehov          #+#    #+#             */
/*   Updated: 2024/10/17 21:45:46 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//C libraries
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

//42 libraries
# include "libft.h"

//Structs
typedef struct s_formatSpecifier
{
	int		bt_length;
}	t_format;

int				ft_printf(const char *format, ...);
//c
t_format		print_chr(int c, t_format *spec);
//s
t_format		print_str(char *c, t_format *spec);
//p
t_format		print_ptr(unsigned long ptr, t_format *spec);
//d || i
t_format		print_num(int num, t_format *spec);
//u
t_format		print_uns(unsigned int num, t_format *spec);
//x || X
t_format		print_hex(unsigned int num, t_format *spec, char *convert);

#endif