/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:24:47 by znichola          #+#    #+#             */
/*   Updated: 2022/11/22 15:24:47 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsystem.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	char	*l;
	size_t	i;

	if (*little == '\0')
		return ((char *)big);
	while (*big != '\0' && len > 0)
	{
		b = (char *)big;
		l = (char *)little;
		i = len;
		while (*b++ == *l++ && i-- > 0)
			if (*l == '\0')
				return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	slen;

	slen = ft_strlen(src);
	if (size > 0)
	{
		if (slen + 1 < size)
			while (*src)
				*dest++ = *src++;
		else if (size != 0)
			while (--size > 0)
				*dest++ = *src++;
		*dest = '\0';
	}
	return (slen);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		return (0);
	while (i < n - 1 && s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = (char *)s;
	while (n > 0)
	{
		*p = '\0';
		p++;
		n--;
	}
}
