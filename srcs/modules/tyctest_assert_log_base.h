/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tyctest_assert_log_base.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:27:04 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/31 17:23:23 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYCTEST_ASSERT_LOG_BASE_H
# define TYCTEST_ASSERT_LOG_BASE_H

# include <string.h>
# include "error_logger.h"
# include "generic_print.h"

/**
 * main logging macro.
 * @param OPERATOR (char *) compare operator (==, !=, <, <=, >, >=)
 * @param ACTUAL (raw) actual value.
 * @param EXPECTED (raw) expected value.
 * @param PLACE_LOG_FUNC (place log macro) place log function (ref. error_logger.h)
 * @param ACTUAL_LOG_FUNC (log macro) value log macro (ref. error_logger.h)
 * @param EXPECTED_LOG_FUNC (log macro) value log macro (ref. error_logger.h)
 */
# define LOG(OPERATOR, ACTUAL, EXPECTED, PLACE_LOG_FUNC, ACTUAL_LOG_FUNC, EXPECTED_LOG_FUNC) \
do { \
	const int	indent_size = 4; \
\
	PLACE_LOG_FUNC(__FILE__, __LINE__, 1 * indent_size, 0); \
	STRING_LOG("Wish", "Actual " OPERATOR " Expected", 2 * indent_size, 8); \
	ACTUAL_LOG_FUNC("Actual", ACTUAL, #ACTUAL, 2 *indent_size, 8); \
	EXPECTED_LOG_FUNC("Expected", EXPECTED, #EXPECTED, 2 * indent_size, 8); \
} while(0)

/**
 * Assert log.
 * @param OPERATOR (char *) compare operator (==, !=, <, <=, >, >=)
 * @param ACTUAL (raw) actual value.
 * @param EXPECTED (raw) expected value.
 * @param ACTUAL_LOG_FUNC (log macro) value log macro (ref. error_logger.h)
 * @param EXPECTED_LOG_FUNC (log macro) value log macro (ref. error_logger.h)
 */
# define ASSERT_LOG(OPERATOR, ACTUAL, EXPECTED, ACTUAL_LOG_FUNC, EXPECTED_LOG_FUNC) \
	LOG(OPERATOR, ACTUAL, EXPECTED, \
		PLACE_LOG_ABORT, ACTUAL_LOG_FUNC, EXPECTED_LOG_FUNC)

/**
 * checker when assert. output assert log and return if conditions are not met.
 * @param condition (value) condition
 * @param LOG_PROC (code) code when conditions are not met.
 */
# define ASSERT_CHECK(condition, LOG_PROC) \
do { \
	if (!(condition)) \
	{ \
		LOG_PROC; \
		*failure_flag = 1; /* failure_flag is argument (ref. register_functions.h) */ \
		return ; \
	} \
} while(0)

#endif