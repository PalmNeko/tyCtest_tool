/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_print.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:42:44 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/28 18:05:32 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERIC_PRINT_H
# define GENERIC_PRINT_H

#include <stdio.h>

#define FORMAT(X) _Generic((X), \
    short: "%d", \
    int: "%d", \
    long: "%ld", \
    unsigned int: "%u", \
    unsigned long: "%lu", \
    float: "%.5e", \
    double: "%.5le", \
    char: "%c", \
    char *: "%s", \
    const char const *: "%s" \
    )

#define GENERIC_PRINT(X) \
	do { \ 
		char    format[30]; \
		\
		sprintf(format, "%s", FORMAT(X)); \
		printf(format, X ); \
	} while(0) 

#endif
