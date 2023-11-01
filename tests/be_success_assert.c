/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   be_success_assert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:23:09 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/01 12:47:23 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tyctest.h"
#include <limits.h>

TEST(BeSuccess, ASSERT_TRUE)
{
	ASSERT_TRUE(1);
}

TEST(BeSuccess, ASSERT_FALSE)
{
	ASSERT_FALSE(0);
}

TEST(BeSuccess, ASSERT_EQ)
{
	ASSERT_EQ((long)((unsigned long long)LONG_MAX + 1), LONG_MIN);
}

TEST(BeSuccess, ASSERT_NE)
{
	ASSERT_NE(1, 0);
	ASSERT_NE(0, 1);
}

TEST(BeSuccess, ASSERT_LT)
{
	ASSERT_LT(1, 2);
	ASSERT_LT(-1, 0);
}

TEST(BeSuccess, ASSERT_LE)
{
	ASSERT_LE(1, 1);
	ASSERT_LE(1, 2);
	ASSERT_LT(-1, 0);
}

TEST(BeSuccess, ASSERT_GT)
{
	ASSERT_GT(30, 29);
	ASSERT_GT(0, -1);
}

TEST(BeSuccess, ASSERT_GE)
{
	ASSERT_GE(30, 29);
	ASSERT_GE(30, 30);
	ASSERT_GE(0, -1);
}
