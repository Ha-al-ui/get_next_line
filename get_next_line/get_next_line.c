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

// char	*get_next_line(int fd)
// {

// }

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
 {
    int fd = open("hh", O_RDONLY);
  

    char buffer[64645];
   int bytes_read = read(fd, buffer, 5);

   printf("%s\n ", buffer);

   printf("%d\n ",bytes_read);


    return 0;
}

