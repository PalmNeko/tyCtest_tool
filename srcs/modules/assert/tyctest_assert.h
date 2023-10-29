/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tyctest_assert.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 23:27:30 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/29 19:04:04 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYCTEST_ASSERT_H
# define TYCTEST_ASSERT_H

# include <string.h>
# include "error_logger.h"
# include "generic_print.h"

char	*to_upper_case(char *str);
char	*to_lower_case(char *str);

# define LOG(OPERATOR, ACTUAL, EXPECTED, PLACE_LOG_FUNC, ACTUAL_LOG_FUNC, EXPECTED_LOG_FUNC) \
do { \
	const int	indent_size = 4; \
\
	PLACE_LOG_FUNC(__FILE__, __LINE__, 1 * indent_size, 0); \
	STRING_LOG("Wish", "Actual " OPERATOR " Expected", 2 * indent_size, 8); \
	ACTUAL_LOG_FUNC("Actual", ACTUAL, #ACTUAL, 2 *indent_size, 8); \
	EXPECTED_LOG_FUNC("Expected", EXPECTED, #EXPECTED, 2 * indent_size, 8); \
} while(0)

# define ASSERT_LOG(OPERATOR, ACTUAL, EXPECTED, ACTUAL_LOG_FUNC, EXPECTED_LOG_FUNC) \
	LOG(OPERATOR, ACTUAL, EXPECTED, \
		PLACE_LOG_ABORT, ACTUAL_LOG_FUNC, EXPECTED_LOG_FUNC)


# define ASSERT_CHECK(condition, LOG_PROC) \
do { \
	if (!(condition)) \
	{ \
		LOG_PROC; \
		return ; \
	} \
} while(0)

#define ASSERT_TRUE(condition) \
	ASSERT_CHECK(condition, \
		ASSERT_LOG("==", condition, "true", \
			VALUE_LOG_BOOL, \
			VALUE_LOG_STRING_RAW)) 

/*
#define ASSERT_FALSE(condition) \
	assert(!condition)

#define ASSERT_EQ(expected, actual) \
	assert(expected == actual)

#define ASSERT_NE(val1, val2) \
	assert(val1 != val2)

#define ASSERT_LT(val1, val2) \
	assert(val1 < val2)

#define ASSERT_LE(val1, val2) \
	assert(val1 <= val2)

#define ASSERT_GT(val1, val2) \
	assert(val1 > val2)

#define ASSERT_GE(val1, val2) \
	assert(val1 >= val2)

#define ASSERT_STREQ(expected_str, actual_str) \
	assert(strcmp(expected_str, actual_str))

#define ASSERT_STRNE(str1, str2) \
	assert(!strcmp(expected_str, actual_str))

#define ASSERT_STRCASEEQ(expected_str, actual_str) \
	do { \
		char	*cast_expected; \
		char	*cast_actual; \
	\
		cast_expected = to_upper_case(expected_str); \
		cast_actual = to_upper_case(actual_str); \
		assert(strcmp(cast_expected, cast_actual)); \
		free(cast_expected); \
		free(cast_actual); \
	} while(0)

#define ASSERT_STRCASENE(str1, str2) \
	do { \
		char	*cast_expected; \
		char	*cast_actual; \
	\
		cast_expected = to_upper_case(expected_str); \
		cast_actual = to_upper_case(actual_str); \
		assert(!strcmp(cast_expected, cast_actual)); \
		free(cast_expected); \
		free(cast_actual); \
	} while(0)
*/

#endif
