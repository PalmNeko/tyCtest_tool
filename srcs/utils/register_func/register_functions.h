/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_functions.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 22:24:18 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/27 23:27:10 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REGISTER_FUNCTIONS_H
# define REGISTER_FUNCTIONS_H

# define MAX_TEST_FUNCTIONS 1024

typedef void(*t_test_function)(void);

void	register_func(t_test_function test_function);
void	call_function(int index);
int		call_all_functions(void);

#endif