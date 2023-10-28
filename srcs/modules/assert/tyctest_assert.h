/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tyctest_assert.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 23:27:30 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/27 23:37:00 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYCTEST_ASSERT_H
# define TYCTEST_ASSERT_H

# include <string.h>

char	*to_upper_case(char *str);
char	*to_lower_case(char *str);

#define ASSERT_TRUE(condition) \
	assert(condition)

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


#endif
