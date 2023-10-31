/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   be_success_assert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:23:09 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/31 22:23:09 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tyctest.h"

TEST(BeSuccess, ASSERT_TRUE)
{
	ASSERT_TRUE(1);
}

TEST(BeSuccess, ASSERT_FALSE)
{
	ASSERT_FALSE(0);
}
