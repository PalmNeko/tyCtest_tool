/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_raw_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:19:59 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/01 11:33:54 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "utils_str.h"

int	is_raw_number(char *str)
{
	long long			convert_ll;
	unsigned long long	convert_ull;
	char				buffer[64];
	int					compare_result;

	convert_ll = strtoll(str, NULL, 10);
	lltoa(convert_ll, buffer, 10);
	compare_result = strcmp(str, buffer);
	compare_result = strcmp(str, buffer);
	if (compare_result == 0)
		return (1);
	convert_ull = strtoull(str, NULL, 10);
	ulltoa(convert_ull, buffer, 10);
	compare_result = strcmp(str, buffer);
	if (compare_result == 0)
		return (1);
	return (0);
}
