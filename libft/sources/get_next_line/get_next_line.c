/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <dberehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:18:05 by dberehov          #+#    #+#             */
/*   Updated: 2024/10/17 23:10:30 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*after_line(char *buffer)
{
	char	*next;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	next = malloc(sizeof(char) * ((ft_strlen(buffer) - i) + 1));
	if (!next)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		next[j++] = buffer[i++];
	next[j] = '\0';
	free(buffer);
	return (next);
}

char	*write_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*join_free(char *buffer, char *buffer_append)
{
	char	*temp_string;

	temp_string = ft_strjoin(buffer, buffer_append);
	free(buffer);
	return (temp_string);
}

char	*read_line(int fd, char *buffer_output)
{
	char	*text_buffer;
	int		bytes_read;

	if (!buffer_output)
		buffer_output = (char *)ft_calloc(1, sizeof(char));
	text_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!text_buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, text_buffer, BUFFER_SIZE);
		if (bytes_read == -1 || (bytes_read == 0 && buffer_output == NULL))
		{
			free(buffer_output);
			free(text_buffer);
			return (NULL);
		}
		text_buffer[bytes_read] = '\0';
		buffer_output = join_free(buffer_output, text_buffer);
		if (ft_strchr(text_buffer, '\n'))
			break ;
	}
	free(text_buffer);
	return (buffer_output);
}

char	*get_next_line(int fd)
{
	static char	*buffer_stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer_stash = read_line(fd, buffer_stash);
	if (!buffer_stash)
		return (NULL);
	line = write_line(buffer_stash);
	buffer_stash = after_line(buffer_stash);
	return (line);
}

/*
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	fd1 = open("text/beescript.txt", O_RDONLY);
	i = 1;
	while (i < 17)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	printf("\n");
	close(fd1);
	return (0);
}
*/
