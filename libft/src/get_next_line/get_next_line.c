/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maax <maax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:42:43 by malauzie          #+#    #+#             */
/*   Updated: 2024/01/31 11:40:54 by maax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

char	*clean_stash(char *stash, unsigned int i)
{
	char			*tmp;
	unsigned int	j;
	unsigned int	len_tmp;

	len_tmp = ft_strlen(stash) - i;
	tmp = (char *)malloc((len_tmp + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	j = 0;
	while (stash[i])
		tmp[j++] = stash[i++];
	tmp[j] = '\0';
	free(stash);
	return (tmp);
}

static unsigned int	my_str_chr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i + 1);
		i++;
	}
	return (0);
}

char	*fill_line(char *stash, unsigned int *i)
{
	unsigned int	j;
	char			*line;

	*i = my_str_chr(stash, '\n');
	if (*i == 0)
		*i = ft_strlen(stash);
	j = 0;
	line = (char *)malloc((*i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (j < *i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*read_text(char *stash, int fd)
{
	char	*buffer;
	char	*tmp;
	int		nb_read;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	nb_read = 1;
	while (nb_read != 0 && !my_str_chr(stash, '\n'))
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read == 0 && ft_strlen(stash))
			break ;
		else if (nb_read == 0 || nb_read == -1)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[nb_read] = '\0';
		tmp = stash;
		stash = ft_strjoin_and_free(tmp, buffer);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*line;
	unsigned int	i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
	{
		stash = ft_strdup("");
		if (!stash)
			return (NULL);
	}
	i = 0;
	stash = read_text(stash, fd);
	if (!stash)
		return (NULL);
	line = fill_line(stash, &i);
	if (!line)
		return (NULL);
	stash = clean_stash(stash, i);
	return (line);
}

