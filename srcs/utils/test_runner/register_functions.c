/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 22:23:38 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/31 19:13:32 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "register_functions.h"
#include "terminal_coloring.h"
#include "test_runner.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	g_func_cnt;
static t_test_group	g_test_groups[MAX_TEST_FUNCTIONS];

static t_test_group	*get_test_group(t_test_info *register_info);
int					run_all_group_tests(void);

/**
 * register test function.
 * @param test_function test function that register.
 * @param title	group name.
 * @param section test section name.
 */
void	register_func(t_test_function test_function, char *title, char *section)
{
	t_test_info		register_info;
	t_test_group	*parent_group;

	register_info = (t_test_info){
		.title = title,
		.section = section,
		.test_function = test_function,
		.is_success = 0,
	};
	parent_group = get_test_group(&register_info);
	if (parent_group == NULL && g_func_cnt == MAX_TEST_FUNCTIONS)
	{
		fprintf(stderr, "%s: %s\n", "over: MAX_TEST_FUNCTIONS ", title);
		exit(1);
	}
	else if (parent_group == NULL)
	{
		parent_group = &g_test_groups[g_func_cnt++];
		parent_group->stored_cnt = 0;
		parent_group->title = title;
	}
	if (parent_group->stored_cnt == MAX_CHILD_TESTS)
	{
		fprintf(stderr, "%s: %s\n", "over: MAX_CHILD_TESTS ", section);
		exit(1);
	}
	parent_group->child_tests[(parent_group->stored_cnt)++] = register_info;
	return ;
}

/**
 * get group
 * @param register_info register function info
 */
static t_test_group	*get_test_group(t_test_info *register_info)
{
	int	index;

	index = 0;
	while (index < g_func_cnt)
	{
		if (strcmp(g_test_groups[index].title, register_info->title) == 0)
			return (&g_test_groups[index]);
		index++;
	}
	return (NULL);
}

/**
 * run all group tests.
 */
int	run_all_group_tests(void)
{
	run_test_groups(g_test_groups, g_func_cnt);
	return (0);
}

t_test_group *get_test_groups(void)
{
	return (g_test_groups);
}

int	get_test_groups_cnt(void)
{
	return (g_func_cnt);
}