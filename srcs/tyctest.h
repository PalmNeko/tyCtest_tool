
#ifndef TYCTEST_H
# define TYCTEST_H

# include "register_functions.h"
# include "register_macro.h"
# include "assert_functions.h"

/**
 * create tests.
 * @param TITLE test group name.
 * @param SECTION test case.
 * @example
 * TEST(BigTest, details) {
 *     ASSERT_TRUE(1);
 * }
 */
# define TEST(TITLE, SECTION) \
	void TITLE ## SECTION (int *failure_flag); /* this function format is defined `register_functions.h`*/ \
	REGISTER_TEST(TITLE, SECTION) \
	void TITLE ## SECTION (int *failure_flag) /* this function format is defined `register_functions.h`*/

/**
 * run all created tests.
 */
# define RUN_ALL_TESTS() run_all_group_tests()

// /**
//  * test that condition is equal to true.
//  * @throw
//  * @param condition condition
//  */
// #define ASSERT_TRUE(condition) \
// 	ASSERT_CHECK(condition, \
// 		ASSERT_LOG("==", condition, "true", \
// 			VALUE_LOG_BOOL, \
// 			VALUE_LOG_STRING_RAW)) 

// /**
//  * test that condition is equal to false.
//  * @throw
//  * @param condition condition
//  */
// #define ASSERT_FALSE(condition) \
// 	ASSERT_CHECK(!condition, \
// 		ASSERT_LOG("==", condition, "false", \
// 			VALUE_LOG_BOOL, \
// 			VALUE_LOG_STRING_RAW)) 

#endif