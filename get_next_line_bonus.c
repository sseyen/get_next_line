/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:21:25 by alisseye          #+#    #+#             */
/*   Updated: 2024/10/12 22:46:35 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_updbuffer(char *new, char *buffer)
{
	char	*tmp;

	if (!buffer)
		buffer = ft_strdup(new);
	else
	{
		tmp = ft_strjoin(buffer, new);
		free(buffer);
		buffer = tmp;
	}
	return (buffer);
}

char	*ft_getrest(char *buffer)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!tmp)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		tmp[j++] = buffer[i++];
	tmp[j] = '\0';
	free(buffer);
	return (tmp);
}

char	*ft_getline(char *buffer)
{
	int		i;
	int		len;
	char	*line;

	if (!buffer || !buffer[0])
		return (NULL);
	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (buffer[len] && buffer[len] == '\n')
		len++;
	if (len == 0)
		return (NULL);
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_fillbuffer(int fd, char *buffer)
{
	char	*new;
	int		ret;

	new = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!new)
		return (NULL);
	ret = read(fd, new, BUFFER_SIZE);
	while (ret > 0)
	{
		new[ret] = '\0';
		buffer = ft_updbuffer(new, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
		ret = read(fd, new, BUFFER_SIZE);
	}
	if (ret < 0)
	{
		free(buffer);
		free(new);
		return (NULL);
	}
	free(new);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[FOPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FOPEN_MAX)
		return (NULL);
	buffer[fd] = ft_fillbuffer(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_getline(buffer[fd]);
	if (!line)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = ft_getrest(buffer[fd]);
	return (line);
}
