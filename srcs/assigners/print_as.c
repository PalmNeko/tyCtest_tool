/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_as.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:39:12 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/04 10:39:12 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void print_as_short(void *value)
{
	fprintf(stderr, "%hd", *(short *)value);
	return ;
}

void print_as_int(void *value)
{
	fprintf(stderr, "%d", *(int *)value);
	return ;
}

void print_as_long(void *value)
{
	fprintf(stderr, "%ld", *(long *)value);
	return ;
}

void print_as_long_long(void *value)
{
	fprintf(stderr, "%lld", *(long long *)value);
	return ;
}

void print_as_unsigned_int(void *value)
{
	fprintf(stderr, "%u", *(unsigned int *)value);
	return ;
}

void print_as_unsigned_long(void *value)
{
	fprintf(stderr, "%lu", *(unsigned long *)value);
	return ;
}

void print_as_unsigned_long_long(void *value)
{
	fprintf(stderr, "%llu", *(unsigned long long *)value);
	return ;
}

void print_as_float(void *value)
{
	fprintf(stderr, "%f", *(float *)value);
	return ;
}

void print_as_double(void *value)
{
	fprintf(stderr, "%f", *(double *)value);
	return ;
}

void print_as_char(void *value)
{
	fprintf(stderr, "%c", *(char *)value);
	return ;
}

void print_as_char_pointer(void *value)
{
	fprintf(stderr, "%s", *(char **)value);
	return ;
}

void print_as_const_char_pointer(void *value)
{
	fprintf(stderr, "%s", *(const char **)value);
	return ;
}

void print_as_void_pointer(void *value)
{
	fprintf(stderr, "%p", value);
	return ;
}
