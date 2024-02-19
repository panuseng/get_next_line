/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaophit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:14:29 by plaophit          #+#    #+#             */
/*   Updated: 2024/02/19 23:11:15 by plaophit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getline(char **buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!(*buffer)[i])
		return (NULL);
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	line = ft_calloc(i + 1 + ((*buffer)[i] == '\n'), sizeof(char));
	if (!line)
	{
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	i = 0;
	while ((*buffer)[i] && (*buffer)[i] != '\n')
	{
		line[i] = (*buffer)[i];
		i++;
	}
	if ((*buffer)[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_tonext(char *buffer)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	next = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!next)
	{
		free(buffer);
		return (NULL);
	}
	i++;
	j = 0;
	while (buffer[i])
		next[j++] = buffer[i++];
	free(buffer);
	return (next);
}

void	*free2(char *buffer, char *res, int mode)
{
	if (mode == 1)
	{
		free(buffer);
		free(res);
	}
	else
		free(res);
	return (NULL);
}

char	*read_file(int fd, char *res)
{
	char	*buffer;
	int		byteread;

	if (!res)
		res = ft_calloc(1, 1);
	if (!res)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (free2(buffer, res, 0));
	byteread = 1;
	while (byteread > 0)
	{
		byteread = read(fd, buffer, BUFFER_SIZE);
		if (byteread == -1)
			return (free2(buffer, res, 1));
		buffer[byteread] = 0;
		res = ft_free(res, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_getline(&buffer);
	if (buffer)
		buffer = ft_tonext(buffer);
	return (line);
}

// int	main()
// {
//     int fd = open("", O_RDONLY); // Ensure the file name is correct
//     if (fd == -1) {
//         // Handle error
//         return 1;
//     }

//     char *line;
//     while ((line = get_next_line(fd)) != NULL) {
//         printf("%s", line);
//         free(line); // Free each line after use
//     }

//     close(fd); // Don't forget to close the file descriptor
//     return 0;
// }
