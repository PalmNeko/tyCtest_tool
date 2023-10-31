/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   be_failure_assert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:59:03 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/31 18:59:16 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tyctest.h"

TEST(BeFailure, ASSERT_TRUE)
{
	ASSERT_TRUE(0);
}

TEST(BeFailure, ASSERT_FALSE)
{
	ASSERT_FALSE(1);
}
