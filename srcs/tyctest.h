
#ifndef TYCTEST_H
# define TYCTEST_H

# include "error_logger.h"
# include "generic_print.h"
# include "register_functions.h"
# include "tyctest_assert_log_base.h"
# include "register_macro.h"

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
	void TITLE ## SECTION (void); \
	REGISTER_TEST(TITLE, SECTION) \
	void TITLE ## SECTION (void)

/**
 * run all created tests.
 */
# define RUN_ALL_TESTS() call_all_functions()

/**
 * test that condition is equal to true.
 * @throw
 * @param condition condition
 */
#define ASSERT_TRUE(condition) \
	ASSERT_CHECK(condition, \
		ASSERT_LOG("==", condition, "true", \
			VALUE_LOG_BOOL, \
			VALUE_LOG_STRING_RAW)) 

#endif