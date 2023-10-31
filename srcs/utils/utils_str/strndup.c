/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strndup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:31:57 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/31 23:31:57 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

#ifdef WINDOWS

char *strndup(char *str, size_t len)
{
	size_t	str_len;
	char	*copy;

	str_len = strnlen(str, len);
	copy = (char *)malloc(sizeof(char) * (str_len + 1));
	if (copy == NULL)
		return (NULL);
	strncpy(copy, str, str_len);
	return (copy);
}

#endif