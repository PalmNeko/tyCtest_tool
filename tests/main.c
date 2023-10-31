/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:30:01 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/31 18:29:20 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tyctest.h"

TEST(Gtester, Test)
{
	ASSERT_TRUE(1);
}

TEST(Gtester, Test2)
{
	ASSERT_FALSE(1);
	ASSERT_TRUE(0);
}

TEST(Gtester1, Test)
{
	ASSERT_TRUE(1);
}

TEST(Gtester1, Test2)
{
	ASSERT_TRUE(1);
}

int	main(void)
{
	RUN_ALL_TESTS();
	return (0);
}
