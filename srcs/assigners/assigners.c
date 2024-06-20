/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigners.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:33:20 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/20 16:31:09 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void	*assign_bool(void **variable, bool value)
{
	static bool	inner_value[2];
	static int	cnt;

	inner_value[cnt] = value;
	*variable = &inner_value[cnt];
	cnt = (cnt + 1) % 2;
	return (*variable);
}

void	*assign_short(void **variable, short value)
{
	static short	inner_value[2];
	static int		cnt;

	inner_value[cnt] = value;
	*variable = &inner_value[cnt];
	cnt = (cnt + 1) % 2;
	return (*variable);
}

void	*assign_int(void **variable, int value)
{
	static int	inner_value[2];
	static int	cnt;

	inner_value[cnt] = value;
	*variable = &inner_value[cnt];
	cnt = (cnt + 1) % 2;
	return (*variable);
}

void	*assign_long(void **variable, long value)
{
	static long	inner_value[2];
	static int	cnt;

	inner_value[cnt] = value;
	*variable = &inner_value[cnt];
	cnt = (cnt + 1) % 2;
	return (*variable);
}

void	*assign_long_long(void **variable, long long value)
{
	static long long	inner_value[2];
	static int			cnt;

	inner_value[cnt] = value;
	*variable = &inner_value[cnt];
	cnt = (cnt + 1) % 2;
	return (*variable);
}

void	*assign_unsigned_int(void **variable, unsigned int value)
{
	static unsigned int	inner_value[2];
	static int	cnt;

	inner_value[cnt] = value;
	*variable = &inner_value[cnt];
	cnt = (cnt + 1) % 2;
	return (*variable);
}

void	*assign_unsigned_long(void **variable, unsigned long value)
{
	static unsigned long	inner_value[2];
	static int				cnt;

	inner_value[cnt] = value;
	*variable = &inner_value[cnt];
	cnt = (cnt + 1) % 2;
	return (*variable);
}

void	*assign_unsigned_long_long(void **variable, unsigned long long value)
{
	static unsigned long long	inner_value[2];
	static int					cnt;

	inner_value[cnt] = value;
	*variable = &inner_value[cnt];
	cnt = (cnt + 1) % 2;
	return (*variable);
}

void	*assign_float(void **variable, float value)
{
	static float	inner_value[2];
	static int		cnt;

	inner_value[cnt] = value;
	*variable = &inner_value[cnt];
	cnt = (cnt + 1) % 2;
	return (*variable);
}

void	*assign_double(void **variable, double value)
{
	static double	inner_value[2];
	static int		cnt;

	inner_value[cnt] = value;
	*variable = &inner_value[cnt];
	cnt = (cnt + 1) % 2;
	return (*variable);
}

void	*assign_char(void **variable, char value)
{
	static char	inner_value[2];
	static int	cnt;

	inner_value[cnt] = value;
	*variable = &inner_value[cnt];
	cnt = (cnt + 1) % 2;
	return (*variable);
}

void	*assign_char_pointer(void **variable, char *value)
{
	static char	*inner_value[2];
	static int	cnt;

	inner_value[cnt] = value;
	*variable = inner_value[cnt];
	cnt = (cnt + 1) % 2;
	return (*variable);
}

void	*assign_const_char_pointer(void **variable, const char *value)
{
	static char	*inner_value[2];
	static int	cnt;

	inner_value[cnt] = (char *)value;
	*variable = inner_value[cnt];
	cnt = (cnt + 1) % 2;
	return (*variable);
}

void	*assign_void_pointer(void **variable, void *value)
{
	static void	*inner_value[2];
	static int	cnt;

	inner_value[cnt] = value;
	*variable = inner_value[cnt];
	cnt = (cnt + 1) % 2;
	return (*variable);
}
