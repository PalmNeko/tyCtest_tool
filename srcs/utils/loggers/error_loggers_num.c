/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_loggers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:12:04 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/28 15:17:29 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	error_log_bool(int actual, int expected)
{
	fprintf(stderr, "Actual: %s\n", 
		actual ? "true" : "false");
	fprintf(stderr, "Expected: %s\n",
		expected ? "true" : "false");
	return ;
}

void	error_log_str(char *actual, char *expected)
{
	fprintf(stderr, "Actual: %s\n", actual);
	fprintf(stderr, "Expected: %s\n", expected);
	return ;
}
