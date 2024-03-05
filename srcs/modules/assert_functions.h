/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:36:46 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/01 13:21:21 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSERT_FUNCTIONS_H
# define ASSERT_FUNCTIONS_H

# include "error_logger.h"
# include "generic_print.h"
# include "tyctest_assert_log_base.h"

# include "header.h"

# define NUM_EQ(val1, val2) ((val1) == (val2))
# define NUM_NE(val1, val2) ((val1) != (val2))
# define NUM_LT(val1, val2) ((val1) < (val2))
# define NUM_LE(val1, val2) ((val1) <= (val2))
# define NUM_GT(val1, val2) ((val1) > (val2))
# define NUM_GE(val1, val2) ((val1) >= (val2))

/**
 * test that condition is equal to true.
 * @throw
 * @param condition condition
 */
# define ASSERT_TRUE(condition) \
	ASSERT_CHECK(condition, \
		ASSERT_LOG("==", "true", condition, \
			VALUE_LOG_STRING_RAW, \
			VALUE_LOG_BOOL))

/**
 * test that condition is equal to false.
 * @throw
 * @param condition condition
 */
# define ASSERT_FALSE(condition) \
	ASSERT_CHECK(!(condition), \
		ASSERT_LOG("==", "false", condition, \
			VALUE_LOG_STRING_RAW, \
			VALUE_LOG_BOOL))

/**
 * test that expected is equal to actual.
 * @throw
 * @param expected actual
 */
# define ASSERT_EQ(expected, actual) do { \
	TEST_NUMBER(expected, actual, "==", NUM_EQ, "assert_eq", "\033[31mAbort\033[m"); \
} while (0);

/**
 * test that expected is not equal to actual.
 * @throw
 * @param expected actual
 */
# define ASSERT_NE(expected, actual) do {\
	TEST_NUMBER(expected, actual, "!=", NUM_NE, "assert_ne", "\033[31mAbort\033[m"); \
	if (*failure_flag != 0) return ; \
} while (0)

/**
 * test that expected is less than actual.
 * @throw
 * @param expected actual
 */
# define ASSERT_LT(expected, actual) do {\
	TEST_NUMBER(expected, actual, "<", NUM_LT, "assert_lt", "\033[31mAbort\033[m"); \
	if (*failure_flag != 0) return ; \
} while (0)

/**
 * test that expected is less than or equal to actual.
 * @throw
 * @param expected actual
 */
# define ASSERT_LE(expected, actual) do {\
	TEST_NUMBER(expected, actual, "<=", NUM_LE, "assert_le", "\033[31mAbort\033[m"); \
	if (*failure_flag != 0) return ; \
} while (0)

/**
 * test that expected is greater than to actual.
 * @throw
 * @param expected actual
 */
# define ASSERT_GT(expected, actual) do {\
	TEST_NUMBER(expected, actual, ">", NUM_GT, "assert_gt", "\033[31mAbort\033[m"); \
	if (*failure_flag != 0) return ; \
} while (0)

/**
 * test that expected is greater than or equal to actual.
 * @throw
 * @param expected actual
 */
# define ASSERT_GE(expected, actual) do {\
	TEST_NUMBER(expected, actual, ">=", NUM_GE, "assert_ge", "\033[31mAbort\033[m"); \
	if (*failure_flag != 0) return ; \
} while (0)

/**
 * test that expected is equal to actual.
 * @throw
 * @param expected expected value
 * @param actual actual value
 */
# define ASSERT_STREQ(expected, actual) \
	ASSERT_CHECK(strcmp(expected, actual) == 0, \
		ASSERT_LOG("==", expected, actual, \
			VALUE_LOG_STRING, \
			VALUE_LOG_STRING))

/**
 * test that expected is not equal to actual.
 * @throw
 * @param expected expected value
 * @param actual actual value
 */
# define ASSERT_STRNE(expected, actual) \
	ASSERT_CHECK(strcmp(expected, actual) != 0, \
		ASSERT_LOG("!=", expected, actual, \
			VALUE_LOG_STRING, \
			VALUE_LOG_STRING))

/**
 * test that expected is equal to actual. ignore character case.
 * @throw
 * @param expected expected value
 * @param actual actual value
 */
# define ASSERT_STRCASEEQ(expected, actual) \
	ASSERT_CHECK(stricmp(expected, actual) == 0, \
		ASSERT_LOG("==", expected, actual, \
			VALUE_LOG_STRING, \
			VALUE_LOG_STRING))

/**
 * test that expected is not equal to actual. ignore character case.
 * @throw
 * @param expected expected value
 * @param actual actual value
 */
# define ASSERT_STRCASENE(expected, actual) \
	ASSERT_CHECK(stricmp(expected, actual) != 0, \
		ASSERT_LOG("!=", expected, actual, \
			VALUE_LOG_STRING, \
			VALUE_LOG_STRING))

#endif