/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_logger.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:55:11 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/29 18:27:01 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_LOGGER_H
# define ERROR_LOGGER_H

# include <stdio.h>
# include <stdlib.h>
# include "generic_print.h"
# include "utils_str.h"

void	error_log_bool(int actual, int expected);
void	error_log_str(char *actual, char *expected);

int		is_raw_number(char *str);

/**
 * log place.
 */
# define PLACE_LOG(MSG, FILE_NAME, LINE, INDENT, MSG_WIDTH) \
	fprintf(stderr, "%*s%-*s: %s:%d\n", \
		INDENT, "", MSG_WIDTH, MSG, FILE_NAME, LINE)

# define PLACE_LOG_ABORT(FILE_NAME, LINE, INDENT, MSG_WIDTH) \
	PLACE_LOG("\033[31mAbort\033[m", FILE_NAME, LINE, INDENT, MSG_WIDTH); \

/**
 * log string.
 * @param MSG (char *) message
 * @param RESULT (char *) value
 * @param ARG (char *) argument 
 */
# define VALUE_LOG_STRING(MSG, RESULT, ARG, INDENT_NUM, MSG_WIDTH) \
	do { \
		char	*trimmed; \
\
		trimmed = trimchr(ARG, '"'); \
		if (trimmed == NULL) \
			break ; \
		fprintf (stderr, "%*s%-*s: ", \
			INDENT_NUM, "", MSG_WIDTH, MSG); \
		fprintf(stderr, "\"%s\"", RESULT); \
		if (strcmp(RESULT, trimmed) != 0) \
			fprintf(stderr, " <- %s", ARG); \
		fprintf(stderr, "\n"); \
		free(trimmed); \
	} while (0)

# define VALUE_LOG_STRING_RAW(MSG, RESULT, ARG, INDENT_NUM, MSG_WIDTH) \
	do { \
		char	*trimmed; \
\
		trimmed = trimchr(ARG, '"'); \
		if (trimmed == NULL) \
			break ; \
		fprintf (stderr, "%*s%-*s: ", \
			INDENT_NUM, "", MSG_WIDTH, MSG); \
		fprintf(stderr, "%s", RESULT); \
		if (strcmp(RESULT, trimmed) != 0) \
			fprintf(stderr, " <- %s", ARG); \
		fprintf(stderr, "\n"); \
		free(trimmed); \
	} while (0)

/**
 * Log string.
 * @param MSG (char *) message
 * @param VALUE (char *) value
 * @param INDENT_NUM (int) insert space
 */
# define STRING_LOG(MSG, VALUE, INDENT_NUM, MSG_WIDTH) \
		VALUE_LOG_STRING(MSG, VALUE, VALUE, INDENT_NUM, MSG_WIDTH)

/**
 * log value.
 * @param MSG (char *) message
 * @param RESULT (any number) RESULT of ARG 
 * @param ARG (char *) ARG of string.
*/
# define VALUE_LOG_NUM(MSG, RESULT, ARG, INDENT_NUM, MSG_WIDTH) \
	do { \
		fprintf (stderr, "%*s%-*s: ", \
			INDENT_NUM, "", MSG_WIDTH, MSG); \
		GENERIC_FPRINT(stderr, RESULT); \
		if (is_raw_number(ARG)) \
			fprintf(stderr, " <- %s", ARG); \
		fprintf(stderr, "\n"); \
	} while (0)

/**
 * log value for boolean.
 * @param MSG (char *) message
 * @param RESULT (any nubmer) RESULT of ARG 
 * @param ARG (char *) ARG of string.
*/
# define VALUE_LOG_BOOL(MSG, RESULT, ARG, INDENT_NUM, MSG_WIDTH) \
	do { \
		fprintf (stderr, "%*s%-*s: ", \
			INDENT_NUM, "", MSG_WIDTH, MSG); \
		GENERIC_FPRINT_BOOL(stderr, RESULT); \
		fprintf(stderr, " <- %s\n", ARG); \
	} while (0)

#endif