/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:35:08 by halaoui           #+#    #+#             */
/*   Updated: 2023/04/01 20:35:18 by halaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  GET_NEXT_LINE_BONUS_H
# define  GET_NEXT_LINE_BONUS_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

# ifndef  BUFFER_SIZE
#  define  BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s1);
int		check_line(char *string);
char	*ft_res(char **string, int j);
char	*ft_line(char **string, char **line, int j);
char	*get_next_too(char *buff, int fd);

#endif
