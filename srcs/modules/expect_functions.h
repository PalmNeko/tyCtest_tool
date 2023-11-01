/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expect_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:42:35 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/01 12:15:11 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPECT_FUNCTIONS_H
# define EXPECT_FUNCTIONS_H

# include "error_logger.h"
# include "generic_print.h"
# include "tyctest_assert_log_base.h"

/**
 * test that condition is equal to true.
 * @param condition condition
 */
# define EXPECT_TRUE(condition) \
	EXPECT_CHECK(condition, \
		EXPECT_LOG("==", "true", condition, \
			VALUE_LOG_STRING_RAW, \
			VALUE_LOG_BOOL))

/**
 * test that condition is equal to true.
 * @param condition condition
 */
# define EXPECT_FALSE(condition) \
	EXPECT_CHECK(!(condition), \
		EXPECT_LOG("==", "false", condition, \
			VALUE_LOG_STRING_RAW, \
			VALUE_LOG_BOOL))

/**
 * test that expected is equal to actual.
 * @param expected actual
 */
# define EXPECT_EQ(expected, actual) \
	EXPECT_CHECK((expected == actual), \
		EXPECT_LOG("==", expected, actual, \
			VALUE_LOG_NUM, \
			VALUE_LOG_NUM))

/**
 * test that expected is not equal to actual.
 * @param expected actual
 */
# define EXPECT_NE(expected, actual) \
	EXPECT_CHECK((expected != actual), \
		EXPECT_LOG("!=", expected, actual, \
			VALUE_LOG_NUM, \
			VALUE_LOG_NUM))

/**
 * test that expected is less than actual.
 * @param expected actual
 */
# define EXPECT_LT(expected, actual) \
	EXPECT_CHECK((expected < actual), \
		EXPECT_LOG("<", expected, actual, \
			VALUE_LOG_NUM, \
			VALUE_LOG_NUM))

/**
 * test that expected is less than or equal to actual.
 * @param expected actual
 */
# define EXPECT_LE(expected, actual) \
	EXPECT_CHECK((expected <= actual), \
		EXPECT_LOG("<=", expected, actual, \
			VALUE_LOG_NUM, \
			VALUE_LOG_NUM))

/**
 * test that expected is greater than to actual.
 * @param expected actual
 */
# define EXPECT_GT(expected, actual) \
	EXPECT_CHECK((expected > actual), \
		EXPECT_LOG(">", expected, actual, \
			VALUE_LOG_NUM, \
			VALUE_LOG_NUM))

/**
 * test that expected is greater than or equal to actual.
 * @param expected actual
 */
# define EXPECT_GE(expected, actual) \
	EXPECT_CHECK((expected >= actual), \
		EXPECT_LOG(">=", expected, actual, \
			VALUE_LOG_NUM, \
			VALUE_LOG_NUM))

#endif