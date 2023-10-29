/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:05:34 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/29 18:19:17 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

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
