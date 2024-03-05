/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lltoa_ulltoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:16:01 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/01 12:31:35 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string.h>
# include <stdio.h>

static void	swap(char *s1, char *s2)
{
	char	tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
	return ;
}

static char *	mystrrev(char *str)
{
	size_t	len;
	size_t	index;


	// fprintf(stderr, "\nstart: %s\n", str);
	len = strlen(str);
	index = 0;
	while(index < len / 2)
	{
		swap(&str[index], &str[len - index - 1]);
		index++;
	}
	// fprintf(stderr, "\nend: %s\n", str);
	return (str);
}

char	*lltoa(long long value, char *buffer, int base)
{
	const char	*base_str = "0123456789abcdefghijklmnopqrstuvwxyz";
	int			index;
	int			minus_flag;
	long long	base_index;

	index = 0;
	minus_flag = 0;
	if (value < 0)
		minus_flag = 1;
	while (value != 0)
	{
		base_index = (value % base);
		buffer[index++] = base_str[base_index < 0 ? -base_index : base_index];
		value /= base;
	}
	if (minus_flag == 1)
		buffer[index++] = '-';
	buffer[index] = '\0';
	mystrrev(buffer);
	return (buffer);
}

char	*ulltoa(unsigned long long value, char *buffer, int base)
{
	const char	*base_str = "0123456789abcdefghijklmnopqrstuvwxyz";
	int			index;

	index = 0;
	while (value != 0)
	{
		buffer[index++] = base_str[value % base];
		value /= base;
	}
	buffer[index] = '\0';
	mystrrev(buffer);
	return (buffer);
}
