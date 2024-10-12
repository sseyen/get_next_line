/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:19:03 by alisseye          #+#    #+#             */
/*   Updated: 2024/10/12 22:32:15 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

// # define BUFFER_SIZE 1000000

char	*get_next_line(int fd);
char	*ft_fillbuffer(int fd, char *buffer);
char	*ft_getline(char *buffer);
char	*ft_getrest(char *buffer);
char	*ft_updbuffer(char *new, char *buffer);

char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);

#endif