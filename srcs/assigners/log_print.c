/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:07:46 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/04 11:07:46 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "terminal_coloring.h"
#include "error_logger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void output_string(char *arg, char *result)
{
	char	*trimmed;

	trimmed = trimchr(arg, '"');
	if (trimmed == NULL)
		return ;
	fprintf(stderr, "\"%s\"", result);
	if (strcmp(result, trimmed) != 0)
		fprintf(stderr, " <- %s", arg);
	free(trimmed);
}

void output_number(char *arg, void *result, void (*f_print)(void *value))
{
	f_print(result);
	if (!is_raw_number(arg))
		fprintf(stderr, " <- %s", arg);
}

void output_boolean(char *arg, int *value)
{
	fprintf(stderr, "%s", *value ? "true" : "false");
	fprintf(stderr, " <- %s", arg);
}

typedef void (*print_as_function)(void *value);
print_as_function get_print_as_function(char *type)
{
	typedef struct {
		print_as_function	f_print_as;
		char				*match_type;
	} t_print_as_func;
	t_print_as_func	print_as_functions[] = {
		{.f_print_as = print_as_short, .match_type = "short"},
		{.f_print_as = print_as_int, .match_type = "int"},
		{.f_print_as = print_as_long, .match_type = "long"},
		{.f_print_as = print_as_long_long, .match_type = "long long"},
		{.f_print_as = print_as_unsigned_int, .match_type = "unsigned int"},
		{.f_print_as = print_as_unsigned_long, .match_type = "unsigned long"},
		{.f_print_as = print_as_unsigned_long_long, .match_type = "unsigned long long"},
		{.f_print_as = print_as_float, .match_type = "float"},
		{.f_print_as = print_as_double, .match_type = "double"},
		{.f_print_as = print_as_char, .match_type = "char"},
		{.f_print_as = print_as_char_pointer, .match_type = "char *"},
		{.f_print_as = print_as_const_char_pointer, .match_type = "const char *"},
	};
	const int ary_size = sizeof(print_as_functions) / sizeof(print_as_functions[0]);
	int	i;

	i = 0;
	while (i < ary_size)
	{
		if (strcmp(print_as_functions[i].match_type, type) == 0)
			return (print_as_functions[i].f_print_as);
		i++;
	}
	return (print_as_int);
}

void output_t_macro_argument_info(const char *message, t_macro_argument_info info)
{
	fprintf(stderr, "%8s%-8s: ", "", message);
	if (strcmp(info.print_type, "string") == 0)
		output_string(info.raw, info.value_ptr);
	else if(strcmp(info.print_type, "number") == 0)
		output_number(info.raw, info.value_ptr, get_print_as_function(info.type));
	else if (strcmp(info.print_type, "bool") == 0)
		output_boolean(info.raw, info.value_ptr);
	fprintf(stderr, "\n");
}

void log_print(t_log_info *info)
{
	const int	indent_size = 4;

	// message title
	fprintf(stderr, "%*s%-*s: %s:%d\n",
		1 * indent_size, "", 0, info->caption, info->filename, info->line);
	fprintf(stderr, "%*s%-*s: Expected " BLUE"%s"CL " Actual\n", \
		2 * indent_size, "", 8, "Wish",  info->ope );
	output_t_macro_argument_info("Expected", info->expect_info);
	output_t_macro_argument_info("Actual", info->actual_info);
	return ;
}