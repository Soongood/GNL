/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobbin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:41:57 by trobbin           #+#    #+#             */
/*   Updated: 2019/10/14 22:44:25 by trobbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_readline(char *buffer, char **line)
{
	char *temp_buf;
	int shift;

	shift = 0;
	while (buffer[shift] != '\n')
		if (!buffer[shift++])
		{
			*line = ft_realloc(buffer, shift);
			return (0);
		}
	*line = ft_memcpy(*line, buffer, shift);
	temp_buf = ft_realloc((buffer + shift + 1), ft_strlen(buffer) - shift);
	free(buffer);
	buffer = temp_buf;
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*buf[FD_SETSIZE + 1];
	int		temp;
	int		bytes;

	if (fd >= FD_SETSIZE || fd < 0 || !line)
		return (-1);
	if (buf[fd])
		return (ft_readline(buf[fd], line));
	temp = 0;
	while ((bytes = read(fd, &buf[fd], BUFF_SIZE)))
	{
		temp += bytes;
		if (bytes == BUFF_SIZE)
			buf[fd] = ft_realloc(&buf[fd], temp);
		else
			buf[fd] = ft_realloc(&buf[fd], temp + 1);
	}
	return (ft_readline(buf[fd], line));
}
