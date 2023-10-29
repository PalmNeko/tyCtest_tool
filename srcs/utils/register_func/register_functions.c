/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 22:23:38 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/29 16:41:38 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "register_functions.h"
#include <assert.h>

static int	g_func_cnt;
static t_test_function	g_test_func[MAX_TEST_FUNCTIONS];

void	register_func(t_test_function test_function)
{
	assert(g_func_cnt != MAX_TEST_FUNCTIONS);
	g_test_func[g_func_cnt++] = test_function;
}

void	call_function(int index)
{
	assert(0 <= index && index < g_func_cnt); // TODO: 実行前にアサート設定を修正する。
	g_test_func[index]();
}

int	call_all_functions(void)
{
	int	index;

	index = 0;
	while (index < g_func_cnt)
		call_function(index++);
	return (0);
}
