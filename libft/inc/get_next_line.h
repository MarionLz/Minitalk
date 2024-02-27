/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maax <maax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:11:49 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/31 11:30:19 by maax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif //BUFFER_SIZE

char			*get_next_line(int fd);
char			*clean_stash(char *stash, unsigned int i);
char			*fill_line(char *stash, unsigned int *i);
char			*read_text(char *stash, int fd);
char			*strjoin_and_free(char *s1, char *s2);
char			*ft_strdup(const char *s);
size_t			ft_strlen(const char *s);
unsigned int	str_chr(const char *s, int c);

#endif