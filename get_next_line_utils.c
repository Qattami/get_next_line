/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:02:04 by iqattami          #+#    #+#             */
/*   Updated: 2023/12/07 17:53:41 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char	*ft_strdup(const char *s){
	char	*p;
	int		i;

	i = 0;
	while (s[i])
		i++;
	p = malloc(sizeof(char) * (i + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = 0;
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	sub = malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!sub)
		return (NULL);
	while (len > i)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}

static char	*ft_copy(char *m, char const *s1, char const *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		m[i] = s1[i];
		i++;
	}
	while (s2[j])
		m[i++] = s2[j++];
	m[i] = '\0';
	return (m);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s;
	char	*m;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	m = malloc(sizeof(char) * s);
	if (m == NULL)
		return (NULL);
	m = ft_copy(m, s1, s2);
	return (m);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int character)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)character)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == (char)character)
		return ((char *)str + i);
	return (NULL);
}
