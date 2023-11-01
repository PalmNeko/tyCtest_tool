/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   be_success_experct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:24:43 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/01 12:22:53 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tyctest.h"
#include <limits.h>

TEST(BeSuccess, EXPECT_TRUE)
{
	EXPECT_TRUE(1);
}

TEST(BeSuccess, EXPECT_FALSE)
{
	EXPECT_FALSE(0);
}

TEST(BeSuccess, EXPECT_EQ)
{
	EXPECT_EQ((long)((unsigned long long)LONG_MAX + 1), LONG_MIN);
}

TEST(BeSuccess, EXPECT_NE)
{
	EXPECT_NE(1, 0);
	EXPECT_NE(0, 1);
}

TEST(BeSuccess, EXPECT_LT)
{
	EXPECT_LT(1, 2);
	EXPECT_LT(-1, 0);
}

TEST(BeSuccess, EXPECT_LE)
{
	EXPECT_LE(1, 1);
	EXPECT_LE(1, 2);
	EXPECT_LT(-1, 0);
}

TEST(BeSuccess, EXPECT_GT)
{
	EXPECT_GT(30, 29);
	EXPECT_GT(0, -1);
}

TEST(BeSuccess, EXPECT_GE)
{
	EXPECT_GE(30, 29);
	EXPECT_GE(30, 30);
	EXPECT_GE(0, -1);
}
