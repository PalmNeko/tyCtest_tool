/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_runner_adapter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:34:41 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/05 18:34:41 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

static bool	failure;

void	set_failure(void)
{
	failure = true;
	return ;
}

void	reset_failure(void)
{
	failure = false;
	return ;
}

// HACK: improve function name
bool	is_failure(void)
{
	return (failure);
}

