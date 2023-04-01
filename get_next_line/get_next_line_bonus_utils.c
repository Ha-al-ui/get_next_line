/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:35:34 by halaoui           #+#    #+#             */
/*   Updated: 2023/04/01 20:35:37 by halaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = -1;
	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[++j] != '\0')
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (free(s1), str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*ns;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if ((ft_strlen(s + start)) < len)
		len = ft_strlen(s + start);
	ns = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!ns)
		return (0);
	while (i < len)
	{
		ns[i] = *(s + start + i);
		i++;
	}
	ft_strlcpy(ns, s + start, len + 1);
	return (ns);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	l;
	unsigned int	i;

	i = 0;
	l = ft_strlen(src);
	if (dstsize > 0)
	{
		while ((src[i] != '\0') && (i < dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (l);
}

char	*ft_strdup( char *s1)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (s == 0)
		return (0);
	else
	{
		while (s1[i] != '\0')
		{
			s[i] = s1[i];
			i++;
		}
	}
	s[i] = '\0';
	return (s);
}
