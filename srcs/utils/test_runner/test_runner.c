/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_runner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:06:27 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/31 19:14:23 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal_coloring.h"
#include "test_runner.h"
#include "register_functions.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int run_test_groups(t_test_group g_test_groups[], int	g_func_cnt)
{
	int						index;
	int						tests_cnt;
	int						groups_cnt;
	int						failure_cnt;
	t_failure_tests_info	failure_info;

	tests_cnt = 0;
	index = 0;
	while (index < g_func_cnt)
	{
		tests_cnt += g_test_groups[index].stored_cnt;
		index++;
	}
	groups_cnt = index;
	failure_info.over_flag = 0;
	failure_info.stored_cnt = 0;
	fprintf(stdout, DARK_BLUE "[==========]" CL " Running %d tests from %d test groups.\n",
		tests_cnt, groups_cnt);
	index = 0;
	failure_cnt = 0;
	while (index < g_func_cnt)
		failure_cnt += run_group_tests(&g_test_groups[index++], &failure_info);
	fprintf(stdout, DARK_BLUE "[==========]" CL " Finished %d tests from %d test groups.\n",
		tests_cnt, groups_cnt);
	fprintf(stdout, GREEN "[  PASSED  ]" CL " %d tests.\n",
		tests_cnt - failure_cnt);
	if (failure_cnt > 0)
	{
		fprintf(stdout, RED "[  FAILED  ]" CL " %d tests. listed below:\n",
			failure_cnt);
		index = 0;
		while (index < failure_info.stored_cnt)
		{
			fprintf(stdout, RED "[  FAILED  ]" CL " %s.%s\n",
				failure_info.failure_tests[index]->title,
				failure_info.failure_tests[index]->section);
			index++;
		}
	}
	return (0);
}
/**
 * run group tests
 * @param group group of target.
 */
int	run_group_tests(t_test_group *group, t_failure_tests_info *failure_info)
{
	int	index;
	int	failure_cnt;

	fprintf(stdout, DARK_BLUE "[----------]" CL " %d tests from %s\n",
		group->stored_cnt, group->title);
	index = 0;
	failure_cnt = 0;
	while (index < group->stored_cnt)
		failure_cnt += run_test(&group->child_tests[index++], failure_info);
	fprintf(stdout, DARK_BLUE "[----------]" CL " %d tests from %s\n\n",
		group->stored_cnt, group->title);
	return (failure_cnt);
}

/**
 * run test info
 * @param tset_info run test function info.
 */
int	run_test(t_test_info *test_info, t_failure_tests_info *failure_info)
{
	int	failure_cnt;

	failure_cnt = 0;
	fprintf(stdout, DARK_BLUE "[ RUN      ]" CL " %s.%s\n",
		test_info->title, test_info->section);
	test_info->test_function(&failure_cnt);
	if (failure_cnt == 0)
		fprintf(stdout, GREEN "[       OK ]" CL " %s.%s\n",
			test_info->title, test_info->section);
	else
	{
		fprintf(stdout, RED "[  FAILED  ]" CL " %s.%s\n",
			test_info->title, test_info->section);
		if (failure_info != NULL && failure_info->stored_cnt >= MAX_FAILURE_TESTS)
			failure_info->over_flag = 1;
		else if (failure_info != NULL)
			failure_info->failure_tests[failure_info->stored_cnt++] = test_info;
	}
	return (failure_cnt);
}

void run_test_with_str(char *group_name, char *section)
{
	t_test_group	*test_groups;
	t_test_group	*target_group;
	int				groups_cnt;
	int				group_index;
	int				section_index;

	test_groups = get_test_groups();
	groups_cnt = get_test_groups_cnt();
	group_index = 0;
	while (group_index < groups_cnt
		&& strcmp(test_groups[group_index].title, group_name) != 0)
		group_index++;
	if (group_index >= groups_cnt)
		return ;
	target_group = &test_groups[group_index];
	section_index = 0;
	while (section_index < target_group->stored_cnt
		&& strcmp(target_group->child_tests[section_index].section, section) != 0)
		section_index++;
	if (section_index >= target_group->stored_cnt)
		return ;
	run_test(&target_group->child_tests[section_index], NULL);
}