/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:05:34 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/31 15:13:52 by tookuyam         ###   ########.fr       */
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

/**
 * trim `trim` from both ends of `str`.
 * @param str target
 * @param trim trim character
 */
char	*trimchr(char *str, char trim)
{
	size_t	len;

	while (*str == trim)
		str++;
	len = strlen(str);
	while (len != 0 && str[len - 1] == trim)
		len--;
	return (strndup(str, len));
}
