/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   be_success_experct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:24:43 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/31 22:24:43 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tyctest.h"

TEST(BeSuccess, EXPECT_TRUE)
{
	EXPECT_TRUE(1);
}

TEST(BeSuccess, EXPECT_FALSE)
{
	EXPECT_FALSE(0);
}
