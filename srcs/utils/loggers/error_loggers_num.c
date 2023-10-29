/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_loggers_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:12:04 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/29 16:24:33 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	error_log_num(char const *message, int value)
{
	fprintf(stderr, "%s: %d\n", message, value);
}

void	error_log_bool(char const *message, int value)
{
	fprintf(stderr, "%s: %s\n",
		message, value ? "true" : "false");
}

void	error_log_expected(int expected)
{
	fprintf(stderr, "Expected: %s\n",
		expected ? "true" : "false");
}

void	error_log_str(char *actual, char *expected)
{
	fprintf(stderr, "Actual: %s\n", actual);
	fprintf(stderr, "Expected: %s\n", expected);
	return ;
}
