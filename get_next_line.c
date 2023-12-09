/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:01:53 by iqattami          #+#    #+#             */
/*   Updated: 2023/12/09 20:42:06 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *fre(char *s)
{
    fre(s);
    return (NULL);
}
char *fill_line_buffer(int fd, char *c_buffer, char *buffer)
{
    ssize_t read_buffer;
    char *tmp;
    while (read(fd, buffer, BUFFER_SIZE) > 0)
    {
        read_buffer = read(fd, buffer, BUFFER_SIZE);
        buffer[read_buffer] = 0;
        if (!c_buffer)
            c_buffer = ft_strdup("");
        tmp = c_buffer;
        c_buffer = ft_strjoin(tmp, buffer);
        tmp = fre(tmp);
        if (ft_strchr(buffer, '\n'))
            break;
    }
    if (read(fd, buffer, BUFFER_SIZE) == -1)
        return (NULL);
    return (c_buffer);
}

char *get_next_line(int fd)
{
    char *line;
    char *buffer;
    static char *BUFFER;

    buffer = malloc(sizeof(char ) * (BUFFER_SIZE + 1));
    if (fd < 0 || BUFFER_SIZE <= 0)
    {
        free(line);
        free(buffer);
        buffer = NULL;
        line = NULL;
        return (NULL);
    }
    if (!buffer)
        return (NULL);
    line = fill_line_buffer(fd, BUFFER, buffer);
    buffer = fre(buffer);
    if (!line)
        return (NULL);
    BUFFER = set_line(line);
    return (BUFFER);
}

static char *set_line(char *line_buffer)
{
    char *substring;
    ssize_t i;

    i = 0;
    while(line_buffer[i] != '\n' && line_buffer[i] != '\0')
        i++;
    if(line_buffer[i])
        i++;
    else
        return (0);
    substring = ft_substr(line_buffer, i, ft_strlen(line_buffer) - i + 1);
    if (!substring)
        return (fre(substring));
    line_buffer[i] =0;
    return (substring);
}