
#ifndef TYCTEST_H
# define TYCTEST_H

# include "error_logger.h"
# include "generic_print.h"
# include "register_functions.h"
# include "tyctest_assert_log_base.h"
# include "register_macro.h"

# define TEST(TITLE, SECTION) \
	void TITLE ## SECTION (void); \
	REGISTER_TEST(TITLE, SECTION) \
	void TITLE ## SECTION (void)

# define RUN_ALL_TESTS() call_all_functions()

#define ASSERT_TRUE(condition) \
	ASSERT_CHECK(condition, \
		ASSERT_LOG("==", condition, "true", \
			VALUE_LOG_BOOL, \
			VALUE_LOG_STRING_RAW)) 

#endif