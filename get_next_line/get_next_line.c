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

    while(string[i])
    {
        if(string[i] == '\n')
          return(i + 1);
        i++;
    }
    return(0);
}

char *ft_ft(char *string, int j)
{
    char *s;
    int i;
    i = ft_strlen(string + j);
    s = ft_substr(string, j, i);
    // printf("string ==== %s\n", string);
    return(s);
}

char *ft_line(char *string, char *line, int j)
{
    line = ft_substr(string,0,j);
    string = ft_ft(string,j);
    printf("string ==== %s\n", string);
    printf("line ==== %s\n", line);

    return(line);
}

char *get_next_line(int fd)
{
    static char *string;
    char *buff;
    int i;
    int j;
    char    *line;
    if (fd < 0 || BUFFER_SIZE <= 0)
    return(NULL);
    if(!string)
    {
        string = ft_strdup("");
    }
   buff = malloc(sizeof(char) * BUFFER_SIZE + 1);

    i = read(fd,buff,BUFFER_SIZE);
    while(i >= 0)
    {
        buff[i] = '\0';
        string = ft_strjoin(string, buff);

        j = check_line(string);
        if(j != 0)
        return(ft_line(string,line,j));

         i = read(fd,buff,BUFFER_SIZE);
    }
    return(NULL);
    
}
int main()
 {
    int fd = open("hh", O_RDWR);

     printf("%s", get_next_line(fd));
     printf("%s", get_next_line(fd));

    return 0;
}

