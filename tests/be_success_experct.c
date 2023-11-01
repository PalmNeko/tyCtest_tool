/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   be_success_experct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:24:43 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/01 13:17:01 by tookuyam         ###   ########.fr       */
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

TEST(BeSuccess, EXPECT_STREQ)
{
	EXPECT_STREQ("", "");
	EXPECT_STREQ("a", "a");
	EXPECT_STREQ("abc", "abc");
}

TEST(BeSuccess, EXPECT_STRNE)
{
	EXPECT_STRNE("","a");
	EXPECT_STRNE("a","");
	EXPECT_STRNE("b","a");
	EXPECT_STRNE("a","b");
	EXPECT_STRNE("a","A");
}

TEST(BeSuccess, EXPECT_STRCASEEQ)
{
	EXPECT_STRCASEEQ("", "");
	EXPECT_STRCASEEQ("a", "A");
	EXPECT_STRCASEEQ("abc", "ABC");
	EXPECT_STRCASEEQ("A", "a");
	EXPECT_STRCASEEQ("ABC", "abc");
}

TEST(BeSuccess, EXPECT_STRCASENE)
{
	EXPECT_STRCASENE("","A");
	EXPECT_STRCASENE("A","");
	EXPECT_STRCASENE("B","a");
	EXPECT_STRCASENE("a","B");
}
