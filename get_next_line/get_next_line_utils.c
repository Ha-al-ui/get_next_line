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

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	p;

	p = c;
	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == p)
			return ((char *)s + len);
		len--;
	}
	if (p == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
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
