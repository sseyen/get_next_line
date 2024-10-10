/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:06:54 by alisseye          #+#    #+#             */
/*   Updated: 2024/10/10 19:10:54 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_linelen(int fd, t_list *lst)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (lst)
	{
		if (lst->fd == fd)
		{
			i = 0;
			while (lst->str[i] && lst->str[i] != '\n')
			{
				len++;
				i++;
			}
			if (lst->str[i] && lst->str[i] == '\n')
			{
				len++;
				return (len);
			}
		}
		lst = lst->next;
	}
	return (len);
}

char	*ft_getline(int fd, t_list *lst)
{
	char	*line;
	size_t	i;
	size_t	j;

	line = (char *)malloc(sizeof(char) * (ft_linelen(fd, lst) + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (lst)
	{
		j = 0;
		while (lst->str[j] && lst->str[j] != '\n')
		{
			line[i++] = lst->str[j];
			j++;
		}
		if (lst->str[j] && lst->str[j] == '\n')
		{
			line[i] = '\n';
			line[i + 1] = '\0';
			return (line);
		}
		lst = lst->next;
	}
	return (line);
}

t_list	*ft_lstappend(int fd, t_list *lst, char *buf)
{
	if (!lst)
		lst = ft_lstnew(fd, buf);
	else
	{
		while (lst && lst->next)
			lst = lst->next;
		lst->next = ft_lstnew(fd, buf);
		lst = lst->next;
	}
	return (lst);
}

t_list	*ft_lstfill(int fd, t_list **lst)
{
	char	*buf;
	t_list	*temp;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	buf[BUFFER_SIZE] = '\0';
	temp = *lst;
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{
		temp = ft_lstappend(fd, temp, buf);
		if (!*lst)
			*lst = temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (*lst);
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	lst = ft_lstfill(fd, &lst);
	if (!lst)
		return (NULL);
	line = ft_getline(fd, lst);
	// lst = ft_lstclean(fd, &lst);
	return (line);
}
