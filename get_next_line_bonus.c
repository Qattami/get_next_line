<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:01:53 by iqattami          #+#    #+#             */
/*   Updated: 2023/12/17 00:16:06 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

=======


>>>>>>> parent of 0d16412... ok
#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
<<<<<<< HEAD
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
=======
	free(s);
	return (NULL);
>>>>>>> parent of 0d16412... ok
}

static char	*set_line(char *line_buffer)
{
	char	*substring;
	ssize_t	i;

	i = 0;
	if (!line_buffer[i])
		return (free(line_buffer),line_buffer = NULL, NULL);
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	substring = ft_substr(line_buffer, 0, i + 1);
	if (!substring)
<<<<<<< HEAD
		return (free(substring), NULL);
=======
		return (free(substring), substring = NULL, NULL);
>>>>>>> parent of 0d16412... ok
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
<<<<<<< HEAD
		return (free(buffer), NULL);
	i++;
	next_line = malloc(ft_strlen(buffer) - i + 1);
	if (!next_line)
		return (free(buffer), NULL);
=======
		return (free(buffer), buffer = NULL,NULL);
	next_line = malloc(ft_strlen(buffer) - i + 1);
	if (!next_line)
		return (free(next_line),next_line = NULL, NULL);
	i++;
>>>>>>> parent of 0d16412... ok
	j = 0;
	while (buffer[i])
		next_line[j++] = buffer[i++];
	next_line[j] = '\0';
	free(buffer);
	buffer = NULL;
	return (next_line);
}

char	*fill_line(int fd, char *s_output, char *buffer)
{
	ssize_t	read_buffer;
<<<<<<< HEAD
	char	*buffer;

	read_buffer = 1;
	buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buffer)
		return (NULL);
	while (read_buffer != 0 && !(ft_strchr(s_output, '\n')))
=======

	read_buffer =1;
	while (read_buffer != 0)
>>>>>>> parent of 0d16412... ok
	{
		read_buffer = read(fd, buffer, BUFFER_SIZE);
		if (read_buffer == -1)
		{
			free(buffer);
<<<<<<< HEAD
			return (free(s_output), NULL);
		}
		else if (read_buffer == 0)
			break ;
=======
			buffer = NULL;
			return (free(s_output), s_output = NULL, NULL);
		}
>>>>>>> parent of 0d16412... ok
		buffer[read_buffer] = '\0';
		if (!s_output)
			s_output = ft_strdup("");
		s_output = ft_strjoin(s_output, buffer);
<<<<<<< HEAD
	}
	free(buffer);
=======
		if(ft_strchr(s_output, '\n'))
			break; 
	}
>>>>>>> parent of 0d16412... ok
	return (s_output);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*rest[REST_SIZE];

<<<<<<< HEAD
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, rest[fd], 0) == -1)
		return (NULL);
	rest[fd] = fill_line(fd, rest[fd]);
	if (!rest[fd])
=======
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0 || !buffer)
		return (free(buffer), buffer = NULL, NULL);
	rest[fd] = fill_line(fd, rest[fd], buffer);
	if(!rest[fd])
>>>>>>> parent of 0d16412... ok
		return (NULL);
	buffer = fre(buffer);
	line = set_line(rest[fd]);
	rest[fd] = next_line(rest[fd]);
	return (line);
}