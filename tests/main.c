/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:30:01 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/30 11:54:26 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tyctest.h"

TEST(ABC, CCD)
{
	ASSERT_TRUE(0);
}

int	main(void)
{
	RUN_ALL_TESTS();
	return (0);
}
