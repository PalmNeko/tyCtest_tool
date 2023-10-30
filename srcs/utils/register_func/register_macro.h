/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_macro.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:35:33 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/30 11:51:09 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REGISTER_MACRO_H
# define REGISTER_MACRO_H

#include "register_functions.h"

# define REGISTER_TEST(TITLE, SECTION) \
	__attribute__((constructor)) \
	static void register_ ## TITLE ## SECTION (void) { \
		register_func( TITLE ## SECTION ); \
	}

#endif