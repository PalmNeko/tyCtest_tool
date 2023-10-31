/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:30:01 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/31 19:00:16 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tyctest.h"
#include <string.h>

int	split_group_section(char *value, char **group, char **section)
{
	char	*tmp;

	tmp = strchr(value, '.');
	if (tmp == NULL)
		return (-1);
	*group = value;
	*section = tmp + 1;
	*tmp = '\0';
	return (0);
}

int	main(int argc, char *argv[])
{
	int		index;
	char	*group;
	char	*section;

	if (argc == 1)
	{
		RUN_ALL_TESTS();
		return (0);
	}
	index = 1;
	while (index < argc)
	{
		split_group_section(argv[index], &group, &section);
		RUN_TEST(group, section);
		index++;
	}
	return (0);
}
