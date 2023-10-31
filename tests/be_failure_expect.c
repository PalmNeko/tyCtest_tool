/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   be_failure_expect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:59:54 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/31 19:00:03 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tyctest.h"

TEST(BeFailure, EXPECT_TRUE)
{
	EXPECT_TRUE(0);
}

TEST(BeFailure, EXPECT_FALSE)
{
	EXPECT_FALSE(1);
}
