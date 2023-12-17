/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:01:53 by iqattami          #+#    #+#             */
/*   Updated: 2023/12/17 00:14:58 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char	*fre(char *s)
{
<<<<<<< HEAD
	if (s)
		free(s);
=======
	free(s);
>>>>>>> parent of 0d16412... ok
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
		return (fre(substring), NULL);
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
=======
		return (fre(buffer));
>>>>>>> parent of 0d16412... ok
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
<<<<<<< HEAD
	char	*buffer;

	read_buffer = 1;
	buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buffer)
		return (NULL);
	while (read_buffer != 0 && !(ft_strchr(s_output, '\n')))
=======

	read_buffer =1;
	// if (read_buffer == 0 )
	// 	return (NULL);
	while (read_buffer != 0)
>>>>>>> parent of 0d16412... ok
	{
		read_buffer = read(fd, buffer, BUFFER_SIZE);
		if (read_buffer == -1)
		{
<<<<<<< HEAD
			fre(buffer);
			return (fre(s_output), NULL);
		}
		else if (read_buffer == 0)
			break ;
=======
			buffer = fre(buffer);
			return (fre(s_output));
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
	static char	*rest;

<<<<<<< HEAD
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, rest, 0) == -1)
		return (NULL);
	rest = fill_line(fd, rest);
	if (!rest)
=======
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0 || !buffer)
		return (free(buffer), buffer = NULL, NULL);
	rest = fill_line(fd, rest, buffer);
	if(!rest)
>>>>>>> parent of 0d16412... ok
		return (NULL);
	buffer = fre(buffer);
	line = set_line(rest);
	rest = next_line(rest);
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>
// int main()
// {
// 	int i = open("get_next_line.h", O_RDONLY);
// 	char *c = get_next_line(i);
// 	printf("%s", c);
// 	free(c);
// 	close(i);
// 	printf("%zd\n", read(i, c, 0));
// 	c = get_next_line(i);
// 	printf("%s", c);
// 	free(c);
// }
// int main(void)
// {
//     int fd;
//     char *line;

//     fd = open("hello.txt", O_RDONLY);

//     if (fd == -1)
//     {
//         perror("Error opening file");
//         return (1);
//     }

//     if ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s\n", line);
//         free(line);
//     }else
//     {
//     close(fd);

//     }

//     return (0);
// }
