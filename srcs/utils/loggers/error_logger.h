/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_logger.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:55:11 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/28 18:07:51 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_LOGGER_H
# define ERROR_LOGGER_H

# include <stdio.h>

void	error_log_bool(int actual, int expected);
void	error_log_str(char *actual, char *expected);

# define PLACE_LOG(FILE_NAME, LINE, MSG) \
	fprintf(stderr, "%s:%d: %s\n", FILE_NAME, LINE, MSG)

# define VALUE_OF_LOG(VALUE) \
	fprintf(stderr, "Value of: %s\n", VALUE)

#define BASE_LOG(FILE, LINE, VALUE);

#define BASIC_ERROR_LOG(FILE, LINE, VALUE, ACTUAL, EXPECTED) \
do { \
	PLACE_LOG(FILE, LINE, "Failure"); \
	VALUE_OF_LOG(VALUE); \
	error_log_bool(ACTUAL, EXPECTED); \
} while(0)

#endif