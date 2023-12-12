/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:01:53 by iqattami          #+#    #+#             */
/*   Updated: 2023/12/12 23:45:32 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fre(char *s)
{
	free(s);
	return (NULL);
}

static char	*set_line(char *line_buffer)
{
	char	*substring;
	ssize_t	i;

	i = 0;
	if (!line_buffer[i])
		return (NULL);
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	substring = ft_substr(line_buffer, 0, i + 1);
	if (!substring)
		return (fre(substring));
	return (substring);
}

char	*next_line(char *buffer)
{
	int		i;
	int		j;
	char	*next_line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (fre(buffer));
	next_line = malloc(ft_strlen(buffer) - i + 1);
	if (!next_line)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		next_line[j++] = buffer[i++];
	next_line[j] = '\0';
	free(buffer);
	return (next_line);
}

char	*fill_line(int fd, char *s_output, char *buffer)
{
	ssize_t	read_buffer;

	read_buffer = read(fd, buffer, BUFFER_SIZE);
	if (read_buffer == 0 || !buffer)
		return (NULL);
	while (read_buffer != 0)
	{
        read_buffer = read(fd, buffer, BUFFER_SIZE);
		if (read_buffer == -1)
		{
			buffer = fre(buffer);
			return (fre(s_output));
		}
		buffer[read_buffer] = 0;
		if (!s_output)
			s_output = ft_strdup("");
		s_output = ft_strjoin(s_output, buffer);
		if(ft_strchr(s_output, '\n'))
			break; 
	}
	return (s_output);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*rest;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0 || !buffer)
		return (free(buffer), buffer = NULL, NULL);
	rest = fill_line(fd, rest, buffer);
	if(!rest)
		return (NULL);
	buffer = fre(buffer);
	line = set_line(rest);
	rest = next_line(rest);
	return (line);
}

#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("hello.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }

    if ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }else
    {
    close(fd);

    }

    return (0);
}
