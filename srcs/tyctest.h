
#ifndef TYCTEST_H
# define TYCTEST_H

# include "./utils/test_runner/register_functions.h"
# include "./utils/test_runner/register_macro.h"
# include "./utils/test_runner/test_runner.h"
# include "modules/assert_functions.h"
# include "modules/expect_functions.h"

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
	void TITLE ## SECTION (void); /* this function format is defined `register_functions.h`*/ \
	REGISTER_TEST(TITLE, SECTION) \
	void TITLE ## SECTION (void) /* this function format is defined `register_functions.h`*/

/**
 * run all created tests.
 */
# define RUN_ALL_TESTS() run_all_group_tests()

/**
 * run test.
 */
# define RUN_TEST(GROUP, SECTION) \
	run_test_with_str(GROUP, SECTION)

#endif