/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilla-c <smilla-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:15:28 by smilla-c          #+#    #+#             */
/*   Updated: 2026/02/03 13:00:38 by smilla-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const	*s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
char	*join_free(char *s1, char *s2);
char	*read_until_newline(int fd, char *stash);
char	*extract_line(char *stash);
char	*remove_line(char *stash);
char	*get_next_line(int fd);

#endif
