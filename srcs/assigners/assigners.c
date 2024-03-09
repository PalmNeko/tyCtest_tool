/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigners.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:33:20 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/04 10:33:20 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void	*assign_bool(void **variable, bool value)
{
	*variable = (void *)malloc(sizeof(bool));
	if (*variable == NULL)
		return (NULL);
	*(bool *)(*variable) = value;
	return (*variable);
}

void	*assign_short(void **variable, short value)
{
	*variable = (void *)malloc(sizeof(short));
	if (*variable == NULL)
		return (NULL);
	*(short *)(*variable) = value;
	return (*variable);
}

void	*assign_int(void **variable, int value)
{
	*variable = (void *)malloc(sizeof(int));
	if (*variable == NULL)
		return (NULL);
	*(int *)(*variable) = value;
	return (*variable);
}

void	*assign_long(void **variable, long value)
{
	*variable = (void *)malloc(sizeof(long));
	if (*variable == NULL)
		return (NULL);
	*(long *)(*variable) = value;
	return (*variable);
}

void	*assign_long_long(void **variable, long long value)
{
	*variable = (void *)malloc(sizeof(long long));
	if (*variable == NULL)
		return (NULL);
	*(long long *)(*variable) = value;
	return (*variable);
}

void	*assign_unsigned_int(void **variable, unsigned int value)
{
	*variable = (void *)malloc(sizeof(unsigned int));
	if (*variable == NULL)
		return (NULL);
	*(unsigned int *)(*variable) = value;
	return (*variable);
}

void	*assign_unsigned_long(void **variable, unsigned long value)
{
	*variable = (void *)malloc(sizeof(unsigned long));
	if (*variable == NULL)
		return (NULL);
	*(unsigned long *)(*variable) = value;
	return (*variable);
}

void	*assign_unsigned_long_long(void **variable, unsigned long long value)
{
	*variable = (void *)malloc(sizeof(unsigned long long));
	if (*variable == NULL)
		return (NULL);
	*(unsigned long long *)(*variable) = value;
	return (*variable);
}

void	*assign_float(void **variable, float value)
{
	*variable = (void *)malloc(sizeof(float));
	if (*variable == NULL)
		return (NULL);
	*(float *)(*variable) = value;
	return (*variable);
}

void	*assign_double(void **variable, double value)
{
	*variable = (void *)malloc(sizeof(double));
	if (*variable == NULL)
		return (NULL);
	*(double *)(*variable) = value;
	return (*variable);
}

void	*assign_char(void **variable, char value)
{
	*variable = (void *)malloc(sizeof(char));
	if (*variable == NULL)
		return (NULL);
	*(char *)(*variable) = value;
	return (*variable);
}

void	*assign_char_pointer(void **variable, char *value)
{
	*variable = (void *)malloc(sizeof(char *));
	if (*variable == NULL)
		return (NULL);
	*(char **)variable = value;
	return (*variable);
}

void	*assign_const_char_pointer(void **variable, const char *value)
{
	*variable = (void *)malloc(sizeof(const char *));
	if (*variable == NULL)
		return (NULL);
	*(const char **)variable = value;
	return (*variable);
}

void	*assign_void_pointer(void **variable, void *value)
{
	*variable = value;
	return (*variable);
}
