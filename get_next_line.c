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

int	ft_readline(char **buffer, char **line, int file_d)
{
	size_t		shift;
	int		bytes;
	char	*temp_ptr;
	char	temp_buffer[BUFF_SIZE];

	shift = 0;
	while (!ft_strlen(*buffer) || (*buffer)[shift] != '\n')
	{
		if (!(*buffer)[shift++])
		{
			if ((bytes = read(file_d, temp_buffer, BUFF_SIZE)))
			{
				*buffer = ft_realloc(*buffer, ft_strlen(*buffer) + BUFF_SIZE + 1);
				temp_ptr = ft_memcpy((*buffer) + ft_strlen(*buffer), temp_buffer, bytes);
				return (ft_readline(buffer, line, file_d));
			}
			*line = ft_strdup(*buffer);
			ft_memdel((void **)buffer);
			return (1);
		}
	}
	*line = ft_strsub(*buffer, 0, (!shift) ? 1 : shift);
	temp_ptr = ft_strsub((*buffer) + shift + 1, 0, ft_strlen(*buffer) - shift);
	ft_memdel((void **)buffer);
	*buffer = temp_ptr;
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*buf[FD_SIZE + 1];
	int		bytes;

	if (fd >= FD_SIZE || fd < 0 || !line || !BUFF_SIZE)
		return (-1);
	if (!buf[fd])
	{
		buf[fd] = ft_memalloc(BUFF_SIZE + 1);
		if ((bytes = read(fd, buf[fd], BUFF_SIZE)) <= 0)
		{
			ft_memdel((void **)&buf[fd]);
			if (bytes < 0)
				return (-1);
			*line = NULL;
			return (0);	
		}
	}
	if (buf[fd])
		return (ft_readline(&buf[fd], line, fd));
}
