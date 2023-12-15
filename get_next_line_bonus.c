

#include "get_next_line_bonus.h"

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
		return (free(line_buffer),line_buffer = NULL, NULL);
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	substring = ft_substr(line_buffer, 0, i + 1);
	if (!substring)
		return (free(substring), substring = NULL, NULL);
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
		return (free(buffer), buffer = NULL,NULL);
	next_line = malloc(ft_strlen(buffer) - i + 1);
	if (!next_line)
		return (free(next_line),next_line = NULL, NULL);
	i++;
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

	read_buffer =1;
	while (read_buffer != 0)
	{
        read_buffer = read(fd, buffer, BUFFER_SIZE);
		if (read_buffer == -1)
		{
			free(buffer);
			buffer = NULL;
			return (free(s_output), s_output = NULL, NULL);
		}
		buffer[read_buffer] = '\0';
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
	static char	*rest[REST_SIZE];

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0 || !buffer)
		return (free(buffer), buffer = NULL, NULL);
	rest[fd] = fill_line(fd, rest[fd], buffer);
	if(!rest[fd])
		return (NULL);
	buffer = fre(buffer);
	line = set_line(rest[fd]);
	rest[fd] = next_line(rest[fd]);
	return (line);
}