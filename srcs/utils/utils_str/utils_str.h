/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:10:01 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/29 18:10:34 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_STR_H
# define UTILS_STR_H

char	*trimchr(char *str, char trim);

#ifdef WINDOWS

char *strndup(char *str, size_t len);

#endif


#endif
