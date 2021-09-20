/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleon-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:29:31 by bleon-ba          #+#    #+#             */
/*   Updated: 2021/09/20 16:29:36 by bleon-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_is_new_line(char *str)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (-1);
	return (i);
}

char	*ft_create_line(char *str, int index)
{
	char	*line;
	int		i;

	line = (char *)malloc((index + 2) * sizeof(char));
	if (!line)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	while (str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}

char	*ft_get_line(char *str)
{
	char	*line;
	int		i;

	if (ft_strlen(str) <= 0)
		return (NULL);
	i = ft_is_new_line(str);
	if (i == -1 || i == (int)ft_strlen(str) - 1)
	{
		line = ft_strdup(str);
		return (line);
	}
	line = ft_create_line(str, i);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*static_str;
	char		*buffer;
	char		*line;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (ft_is_new_line(static_str) == -1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buffer[bytes] = '\0';
		static_str = ft_strjoin(static_str, buffer);
	}
	free(buffer);
	if (bytes == -1)
		return (NULL);
	line = ft_get_line(static_str);
	static_str = ft_buffer_cache(static_str);
	return (line);
}
