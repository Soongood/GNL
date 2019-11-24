#include "get_next_line.h"

static int	ft_readline(char **buf, char **line)
{
	char			*temp_ptr;
	char			*nl;

	temp_ptr = *buf;
	nl = ft_strchr(*buf, '\n');
	*line = nl ? ft_strsub(*buf, 0, nl - *buf) : ft_strdup(*buf);
	*buf = nl ? ft_strsub(nl + 1, 0, ft_strlen(nl + 1)) : ft_strnew(0);
	free(temp_ptr);
	return (*line && *buf ? GNL_OK : GNL_ERROR);
}

static t_gnl *find_fd(t_gnl **gnl,const int file_d)
{
	t_gnl *tmp;

	tmp = *gnl;
	while (tmp)
		if ((int)tmp->fd == file_d)
				return (tmp);
		else
				tmp = tmp->next;
	if (!(tmp = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	if (!(tmp->content = ft_strnew(BUFF_SIZE)))
	{
		free(tmp);
		return (NULL);
	}
	tmp->next = *gnl;
	tmp->fd = file_d;
	*gnl = tmp;
	return (tmp);
}

int get_next_line(const int fd, char **line)
{
	char	*temp;
	char	tmp_buf[BUFF_SIZE + 1];
	ssize_t	bytes;
	static	t_gnl *gnl;
	t_gnl	*current;

	if (fd < 0 || !line || read(fd, NULL, 0) < 0 || !(current = find_fd(&gnl, fd)))
		return (GNL_ERROR);
	while ((bytes = read(current->fd, tmp_buf, BUFF_SIZE)))
	{
		temp = current->content;
		tmp_buf[bytes] = '\0';
		current->content = ft_strjoin(current->content, tmp_buf);
		free(temp);
		if (!current->content)
			return (GNL_ERROR);
		if (bytes < BUFF_SIZE || ft_strchr(tmp_buf, '\n'))
			break ;
	}
	if (!bytes && !*current->content)
		return (GNL_EOF);
	return (ft_readline(&current->content, line));
}
