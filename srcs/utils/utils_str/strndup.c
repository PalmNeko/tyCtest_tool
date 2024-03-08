/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strndup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:31:57 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/08 12:27:51 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

#ifdef WINDOWS

char *strndup(char *str, size_t len)
{
	size_t	str_len;
	size_t	str_size;
	char	*copy;

	str_len = strnlen(str, len);
	str_size = str_len + 1;
	copy = (char *)malloc(sizeof(char) * str_size);
	if (copy == NULL)
		return (NULL);
	strncpy(copy, str, str_len);
	copy[str_len] = '\0';
	return (copy);
}

char *strdup(const char *str)
{
	size_t	str_len;
	size_t	str_size;
	char	*copy;

	str_len = strlen(str);
	str_size = str_len + 1;
	copy = (char *)malloc(sizeof(char) * str_size);
	if (copy == NULL)
		return (NULL);
	strncpy(copy, str, str_size);
	copy[str_len] = '\0';
	return (copy);
}

#endif
