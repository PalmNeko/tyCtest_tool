/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   be_failure_expect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:59:54 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/01 13:16:33 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tyctest.h"
#include <limits.h>

TEST(BeFailure, EXPECT_TRUE)
{
	EXPECT_TRUE(0);
}

TEST(BeFailure, EXPECT_FALSE)
{
	EXPECT_FALSE(1);
}

TEST(BeFailure, EXPECT_EQ)
{
	EXPECT_EQ(ULLONG_MAX, (unsigned long long) 0);
}

TEST(BeFailure, EXPECT_NE)
{
	EXPECT_NE(-121323123123, -121323123123);
}

TEST(BeFailure, EXPECT_LT)
{
	EXPECT_LT(1, 1);
}

TEST(BeFailure, EXPECT_LE)
{
	EXPECT_LE(3, 2);
}

TEST(BeFailure, EXPECT_GT)
{
	EXPECT_GT(30, 30);
}

TEST(BeFailure, EXPECT_GE)
{
	EXPECT_GE(29, 30);
}

TEST(BeFailure, EXPECT_STREQ)
{
	EXPECT_STREQ("a", "b");
	EXPECT_STREQ("", "b");
	EXPECT_STREQ("a", "");
}

TEST(BeFailure, EXPECT_STRNE)
{
	EXPECT_STRNE("", "");
	EXPECT_STRNE("a", "a");
	EXPECT_STRNE("abc", "abc");
}

TEST(BeFailure, EXPECT_STRCASEEQ)
{
	EXPECT_STRCASEEQ("","A");
	EXPECT_STRCASEEQ("A","");
	EXPECT_STRCASEEQ("B","a");
	EXPECT_STRCASEEQ("a","B");
}

TEST(BeFailure, EXPECT_STRCASENE)
{
	EXPECT_STRCASENE("", "");
	EXPECT_STRCASENE("a", "A");
	EXPECT_STRCASENE("abc", "ABC");
	EXPECT_STRCASENE("A", "a");
	EXPECT_STRCASENE("ABC", "abc");
}
