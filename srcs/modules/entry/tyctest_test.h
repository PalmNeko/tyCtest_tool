/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tyctest_test.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:02:29 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/27 22:55:11 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYCTEST_TEST_H
# define TYCTEST_TEST_H

#include "register_functions.h"

# define REGISTER_TEST(TITLE, SECTION) \
	__attribute__((constructor)) \
	static void register_ ## TITLE ## SECTION (void) { \
		register_func( TITLE ## SECTION ); \
	}

# define TEST(TITLE, SECTION) \
	void TITLE ## SECTION (void); \
	REGISTER_TEST(TITLE, SECTION) \
	void TITLE ## SECTION (void)

# define RUN_ALL_TESTS() call_all_functions()

#endif