/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:33:49 by halaoui           #+#    #+#             */
/*   Updated: 2023/01/16 22:33:52 by halaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
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
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[++j] != '\0')
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (free(str), str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ns;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if ((ft_strlen(s + start)) < len)
		len = ft_strlen(s + start);
	ns = (char *)malloc(sizeof (char) * (len + 1));
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

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
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

char	*ft_strdup(const char *s1)
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
// void leak_checker(void)
// {
// 		system("leaks a.out");
// }
// int main()
//  {
//   char str[] = "alsk";
//   char s2[]= "dkald";
//   printf("%s\n", ft_strjoin(str,s2));
// 	atexit(leak_checker);
// 	while(1)
// 	{
// 		pause();
// 	}

//   return 0;
// }
