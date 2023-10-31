/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_raw_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:19:59 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/31 23:19:59 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

int is_raw_number(char *str)
{
	long long			convertLL;
	unsigned long long	convertULL;
	char				*tmp_str;
	char				buffer[64];
	int					compare_result;

	convertLL = strtoll(str, NULL, 10);
	tmp_str = lltoa(convertLL, buffer, 10);
	if (tmp_str == NULL)
		return (0);
	compare_result = strcmp(str, tmp_str);
	compare_result = strcmp(str, tmp_str);
	if (compare_result == 0)
		return (1);
	convertULL = strtoull(str, NULL, 10);
	tmp_str = ulltoa(convertULL, buffer, 10);
	if (tmp_str == NULL)
		return (0);
	compare_result = strcmp(str, tmp_str);
	if (compare_result == 0)
		return (1);
	return (0);
}
