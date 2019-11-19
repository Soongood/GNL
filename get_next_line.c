/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobbin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 21:43:06 by trobbin           #+#    #+#             */
/*   Updated: 2019/11/19 06:05:25 by trobbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_readline(char **buf, char **line)
{
	char	*temp_ptr;
	char	*nl;

	temp_ptr = *buf;
	nl = ft_strchr(*buf, '\n');
	*line = nl ? ft_strsub(*buf, 0, nl - *buf) : ft_strdup(*buf);
	*buf = nl ? ft_strsub(nl + 1, 0, ft_strlen(nl + 1)) : ft_strnew(0);
	free(temp_ptr);
	return (*line && *buf ? GNL_OK : GNL_ERROR);
}

int			get_next_line(const int fd, char **line)
{
	ssize_t			bytes;
	static char		*buf[FD_SIZE + 1];
	char			tmp_buf[BUFF_SIZE + 1];
	char			*tmp;

	if (fd >= FD_SIZE || !line || read(fd, NULL, 0) < 0)
		return (GNL_ERROR);
	if (!buf[fd] && (!(buf[fd] = ft_strnew(0))))
		return (GNL_ERROR);
	while ((bytes = read(fd, tmp_buf, BUFF_SIZE)))
	{
		tmp = buf[fd];
		tmp_buf[bytes] = '\0';
		buf[fd] = ft_strjoin(buf[fd], tmp_buf);
		free(tmp);
		if (bytes < BUFF_SIZE || ft_strchr(tmp_buf, '\n'))
			break ;
	}
	if (bytes == 0 && !*buf[fd])
	{
		free(buf[fd]);
		buf[fd] = NULL;
		return (GNL_EOF);
	}
	return (ft_readline(&buf[fd], line));
}
