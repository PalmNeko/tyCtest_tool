/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 22:23:38 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/31 17:38:17 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "register_functions.h"
#include "terminal_coloring.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	g_func_cnt;
static t_test_group	g_test_groups[MAX_TEST_FUNCTIONS];

static t_test_group	*get_test_group(t_test_info *register_info);

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
	parent_group->child_tests[parent_group->stored_cnt++] = register_info;
	return ;
}

/**
 * run test info
 * @param tset_info run test function info.
 */
int	run_test(t_test_info *test_info)
{
	int	failure_cnt;

	failure_cnt = 0;
	fprintf(stdout, BLUE "[ RUN      ]" CL " %s.%s\n",
		test_info->title, test_info->section);
	test_info->test_function(&failure_cnt);
	if (failure_cnt == 0)
		fprintf(stdout, GREEN "[       OK ]" CL " %s.%s\n",
			test_info->title, test_info->section);
	else
		fprintf(stdout, RED "[  FAILED  ]" CL " %s.%s\n",
			test_info->title, test_info->section);
	return (failure_cnt);
}

/**
 * run group tests
 * @param group group of target.
 */
int	run_group_tests(t_test_group *group)
{
	int	index;
	int	failure_cnt;

	fprintf(stdout, BLUE "[----------]" CL " %d tests from %s\n",
		group->stored_cnt, group->title);
	index = 0;
	failure_cnt = 0;
	while (index < group->stored_cnt)
		failure_cnt += run_test(&group->child_tests[index++]);
	fprintf(stdout, BLUE "[----------]" CL " %d tests from %s\n\n",
		group->stored_cnt, group->title);
	return (failure_cnt);
}

/**
 * run all group tests.
 */
int	run_all_group_tests(void)
{
	int	index;
	int	failure_cnt;

	fprintf(stdout, BLUE "[==========]" CL " Running %d tests from %d test case.\n",
		g_func_cnt, g_func_cnt);
	index = 0;
	failure_cnt = 0;
	while (index < g_func_cnt)
		failure_cnt += run_group_tests(&g_test_groups[index++]);
	fprintf(stdout, BLUE "[==========]" CL " Finished %d tests from %d test case.\n",
		g_func_cnt, g_func_cnt);
	fprintf(stdout, GREEN "[  PASSED  ]" CL " %d tests.\n",
		g_func_cnt - failure_cnt);
	if (failure_cnt > 0)
		fprintf(stdout, RED "[  FAILED  ]" CL " %d tests.\n",
			failure_cnt);
	return (0);
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
		if (strcmp(g_test_groups[index].title, register_info->title))
			return (&g_test_groups[index]);
		index++;
	}
	return (NULL);
}
