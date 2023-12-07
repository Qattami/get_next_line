/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:01:53 by iqattami          #+#    #+#             */
/*   Updated: 2023/12/07 20:32:06 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *_fill_line_buffer(int fd, char *left_c, char *buffer)
{
     __ssize_t read_buffer;

    read_buffer = 1;
    while (read_buffer > 0)
    {
        read_buffer = read(fd, buffer, BUFFER_SIZE);
        if(read_buffer == -1)
        {
            free(left_c);
            return (NULL);
        }
        if (read_buffer == 0)
            break;
        buffer[read_buffer] = 0;
        if(!left_c)
            left_c = ft_strdup("");
        left_c = ft_strjoin(left_c ,buffer);
        if (ft_strchr(buffer, '\n'))
            break;
    }
    return (left_c);
}

char *get_next_line(int fd)
{
    char *line;
    char *buffer;
    static char *BUFFER;
    
    buffer = malloc(sizeof(char*) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    if (fd < 0 || BUFFER_SIZE <= 0)
    {
        free(line);
        free(buffer);
        buffer = NULL;
        line = NULL;
        return (NULL);
    }
    
}