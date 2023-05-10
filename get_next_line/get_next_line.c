/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:33:21 by halaoui           #+#    #+#             */
/*   Updated: 2023/03/31 22:00:21 by halaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_line(char *string)
{
	int	i;

	i = 0;
	if (!string)
		return (0);
	while (string[i])
	{
		if (string[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*ft_res(char **string, int j)
{
	char	*s;

	s = ft_substr(*string, j, ft_strlen(*string + j));
	free(*string);
	*string = NULL;
	return (s);
}

char	*ft_line(char **string, char **line, int j)
{
	*line = ft_substr(*string, 0, j);
	*string = ft_res(string, j);
	return (*line);
}

char	*get_next_too(char *buff, int fd)
{
	static char	*string;
	char		*line;
	int			i;
	int			j;

	i = read(fd, buff, BUFFER_SIZE);
	while (i >= 0)
	{
		buff[i] = '\0';
		string = ft_strjoin(string, buff);
		if (!string[0])
			return (free(buff), free(string), string = NULL, NULL);
		j = check_line(string);
		if (j != 0)
			return (free(buff), ft_line(&string, &line, j));
		if (!i && string)
			return (free(buff), ft_res(&string, j));
		i = read(fd, buff, BUFFER_SIZE);
	}
	return (free(buff), free(string), string = NULL, NULL);
}

char	*get_next_line(int fd)
{
	char	*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	else
		return (get_next_too(buff, fd));
}
