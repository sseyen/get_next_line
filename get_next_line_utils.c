/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:06:56 by alisseye          #+#    #+#             */
/*   Updated: 2024/10/10 19:09:25 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

t_list	*ft_lstnew(int fd, char *str)
{
	size_t	i;
	t_list	*new;
	char	*new_str;

	if (!str || !*str)
		return (NULL);
	new = (t_list *)malloc(sizeof(t_list));
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!new || !new_str)
		return (NULL);
	new->fd = fd;
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	new->str = new_str;
	new->next = NULL;
	return (new);
}

// t_list	*ft_free(int fd, t_list **lst)
// {
// 	t_list	*cur;
// 	t_list	*prev;

// 	cur = *lst;
// 	prev = NULL;
// 	while (cur)
// 	{
// 		if (cur->fd == fd)
// 		{
// 			if (prev)
// 				prev->next = cur->next;
// 			else
// 				*lst = cur->next;
// 			free(cur->str);
// 			free(cur);
// 			return (*lst);
// 		}
// 		prev = cur;
// 		cur = cur->next;
// 	}
// 	return (*lst);
// }

// t_list	*ft_lstclean(int fd, t_list **lst)
// {
// 	t_list	*temp;

// 	temp = ft_free(fd, lst);
// 	while (!ft_strchr(temp->str, '\n'))
// 	{
// 	}
// }
