/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:34:34 by halaoui           #+#    #+#             */
/*   Updated: 2023/04/03 21:33:17 by halaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_ft(char **string, int j)
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
	*string = ft_ft(string, j);
	return (*line);
}

char	*get_next_too(char *buff, int fd)
{
	static char	*string[OPEN_MAX];
	char		*line;
	int			i;
	int			j;

	if (fd > OPEN_MAX)
		return (NULL);
	i = read(fd, buff, BUFFER_SIZE);
	while (i >= 0)
	{
		buff[i] = '\0';
		string[fd] = ft_strjoin(string[fd], buff);
		if (!string[fd][0])
			return (free(buff), free(string[fd]), string[fd] = NULL, NULL);
		j = check_line(string[fd]);
		if (j != 0)
			return (free(buff), ft_line(&string[fd], &line, j));
		if (!i && string[fd])
			return (free(buff), ft_ft(&string[fd], j));
		i = read(fd, buff, BUFFER_SIZE);
	}
	return (free(buff), free(string[fd]), string[fd] = NULL, NULL);
}

char	*get_next_line(int fd)
{
	char	*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	else if (buff != '\0')
		return (get_next_too(buff, fd));
	else
		return (free(buff), NULL);
}
