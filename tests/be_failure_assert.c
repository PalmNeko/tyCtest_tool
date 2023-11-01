/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   be_failure_assert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:59:03 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/01 12:47:26 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tyctest.h"
#include <limits.h>

TEST(BeFailure, ASSERT_TRUE)
{
	ASSERT_TRUE(0);
}

TEST(BeFailure, ASSERT_FALSE)
{
	ASSERT_FALSE(1);
}

TEST(BeFailure, ASSERT_EQ)
{
	ASSERT_EQ(ULLONG_MAX, (unsigned long long) 0);
}

TEST(BeFailure, ASSERT_NE)
{
	ASSERT_NE(-121323123123, -121323123123);
}

TEST(BeFailure, ASSERT_LT)
{
	ASSERT_LT(1, 1);
}

TEST(BeFailure, ASSERT_LE)
{
	ASSERT_LE(3, 2);
}

TEST(BeFailure, ASSERT_GT)
{
	ASSERT_GT(30, 30);
}

TEST(BeFailure, ASSERT_GE)
{
	ASSERT_GE(29, 30);
}
