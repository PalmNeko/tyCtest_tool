/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:36:46 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/31 18:40:17 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSERT_FUNCTIONS_H
# define ASSERT_FUNCTIONS_H

# include "error_logger.h"
# include "generic_print.h"
# include "tyctest_assert_log_base.h"

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

/**
 * test that condition is equal to false.
 * @throw
 * @param condition condition
 */
#define ASSERT_FALSE(condition) \
	ASSERT_CHECK(!condition, \
		ASSERT_LOG("==", condition, "false", \
			VALUE_LOG_BOOL, \
			VALUE_LOG_STRING_RAW)) 

#endif