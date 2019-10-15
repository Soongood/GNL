/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobbin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:41:57 by trobbin           #+#    #+#             */
/*   Updated: 2019/10/16 01:05:08 by trobbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_readline(char *buffer, char **line, int file_d)
{
	size_t		shift;
	int		bytes;
	char	*temp_ptr;
	char	temp_buffer[BUFF_SIZE];

	shift = 0;
	while (buffer[shift] != '\n')
	{
		if (!buffer[shift])
		{
			if ((bytes = read(file_d, temp_buffer, BUFF_SIZE)))
			{
				temp_ptr = buffer;
				buffer = ft_realloc(buffer + shift, ft_strlen(temp_buffer) + 1);
				buffer = temp_ptr;
				return (ft_readline(buffer, line, file_d));
			}
			*line = ft_strcpy(*line, buffer);
			return (0);
		}
		shift++;
	}
	*line = ft_memcpy((void *)*line, (void *)buffer, shift + 1);
	temp_ptr = ft_realloc(buffer + shift + 1, ft_strlen(buffer) - shift - 1);
	free(buffer);
	buffer = temp_ptr;
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*buf[OPEN_MAX + 1];
	int		bytes;

	if (fd >= OPEN_MAX || fd < 0 || !line || !BUFF_SIZE)
		return (-1);
	if (!buf[fd])
	{
		buf[fd] = ft_realloc(buf[fd], BUFF_SIZE + 1);
		if ((bytes = read(fd, buf[fd], BUFF_SIZE)) <= 0)
			return (-1);
	}
	return (ft_readline(buf[fd], line, fd));
}
