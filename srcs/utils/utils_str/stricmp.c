/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stricmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:08:25 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/01 13:13:03 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ctype.h>

int	stricmp(const char *string1, const char *string2)
{
	while (*string1 != '\0' && *string1 != '\0')
	{
		if (toupper(*string1) != toupper(*string2))
			return ((int)toupper(*string1) - toupper(*string2));
		string1++;
		string2++;
	}
	return ((int)toupper(*string1) - toupper(*string2));
}
