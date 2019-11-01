/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobbin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 21:43:06 by trobbin           #+#    #+#             */
/*   Updated: 2019/11/01 17:01:22 by trobbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_readline(char **buf, char **line, int file_d)
{
	size_t			shift;
	int				bytes;
	char			*temp_ptr;
	char			temp_buf[BUFF_SIZE];

	shift = 0;
	while (!ft_strlen(*buf) || (*buf)[shift] != '\n')
		if (!(*buf)[shift++])
		{
			if ((bytes = read(file_d, temp_buf, BUFF_SIZE)))
			{
				*buf = ft_realloc(*buf, ft_strlen(*buf) + bytes + 1);
				temp_ptr = ft_memcpy((*buf) + ft_strlen(*buf), temp_buf, bytes);
				continue ;
			}
			*line = ft_strlen(*buf) ? ft_strdup(*buf) : NULL;
			ft_memdel((void **)buf);
			return (*line ? 1 : 0);
		}
	*line = ft_strsub(*buf, 0, shift);
	temp_ptr = ft_strsub((*buf) + shift + 1, 0, ft_strlen(*buf) - shift);
	ft_memdel((void **)buf);
	*buf = temp_ptr;
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char		*buf[FD_SIZE + 1];
	int				bytes;

	if (fd >= FD_SIZE || fd < 0 || !line || !BUFF_SIZE)
		return (-1);
	if (!buf[fd])
	{
		buf[fd] = ft_memalloc(BUFF_SIZE + 1);
		if ((bytes = read(fd, buf[fd], BUFF_SIZE)) <= 0)
		{
			ft_memdel((void **)&buf[fd]);
			*line = NULL;
			return (!bytes ? 0 : -1);
		}
	}
	if (buf[fd])
		return (ft_readline(&buf[fd], line, fd));
	return (1);
}
