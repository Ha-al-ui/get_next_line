/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:33:21 by halaoui           #+#    #+#             */
/*   Updated: 2023/01/16 22:33:23 by halaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int check_line(char *string)
{
    int i;
    i = 0;
    if(!string)
        return(0);
    while(string[i])
    {
        if(string[i] == '\n')
          return(i + 1);
        i++;
    }
    return(0);
}

char *ft_ft(char **string, int j)
{
    char *s;
    s = ft_substr(*string, j, ft_strlen(*string + j));
    *string = NULL;
    free(*string);
    return(s);
}

char *ft_line(char **string, char **line, int j)
{
    *line = ft_substr(*string,0,j);
    *string = ft_ft(string,j);
    return(*line);
}

char *get_next_line(int fd)
{
    static char *string;
    char *buff;
    int i = 0;
    int j;
    char    *line = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return(NULL);
    buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if(!buff)  
        return(NULL);
    i = read(fd, buff, BUFFER_SIZE);

    while(i >= 0)
    {
        buff[i] ='\0';
        string = ft_strjoin(string, buff);
         if(!string[0])
            return(NULL);
        j = check_line(string);
        if(j != 0)
            return(ft_line(&string,&line,j));
        if(!i && string)
            return(ft_ft(&string,j));
        i = read(fd,buff,BUFFER_SIZE);
    }
    return(NULL);
    
}

// int main()
// {
//     int fd = open("get_next_line.c", O_RDWR);
//     char *p;
//     while((p = get_next_line(fd)))
//     {
//         printf("%s", p);
//     }

// }

