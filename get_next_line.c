#include "get_next_line.h"

int	ft_readline(char **buf, char **line, int file_d)
{
	size_t			shift;
	int				bytes;
	char			*temp_ptr;
	char			temp_buf[BUFF_SIZE];

	shift = 0;
	while (!(**buf) || (*buf)[shift ? shift - 1 : 0] != '\n')
		if (!(*buf)[shift++])
		{
			if ((bytes = read(file_d, temp_buf, BUFF_SIZE)))
			{
				if (!(*buf = ft_realloc(*buf, ft_strlen(*buf) + bytes + 1)))
					return (-1);
				temp_ptr = ft_memcpy((*buf) + ft_strlen(*buf), temp_buf, bytes);
				continue ;
			}
			*line = ft_strlen(*buf) ? ft_strdup(*buf) : '\0';
			ft_memdel((void **)buf);
			return (*line ? 1 : 0);
		}
	*line = ft_strsub(*buf, 0, (shift = shift ? shift - 1 : shift));
	temp_ptr = ft_strsub((*buf) + shift + 1, 0, ft_strlen(*buf) - shift);
	ft_memdel((void **)buf);
	*buf = temp_ptr;
	return (1);
}

t_list *find_fd(t_list **gnl, int file_d)
{
	t_list *tmp;

	tmp = *gnl;
	while (tmp)
	{
		if ((int)tmp->content_size == file_d)
				return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if ((tmp->content = ft_memalloc(BUFF_SIZE + 1)))
	{
		tmp->content_size = file_d;
		tmp->next = NULL;
		ft_lstadd(gnl, tmp);
		tmp = *gnl;
		return (tmp);
	}
	return (NULL);
}

int get_next_line(const int fd, char **line)
{
	static	t_list *gnl;
	t_list	*current;

	if (!(current = find_fd(&gnl, fd)) || !line || fd < 0 
									|| read(fd, NULL, 0) < 0)
		return (-1);
	if (!(current->content))
	{
			*line = '\0';
			return (0);
	}
	return (ft_readline((char **)&(current->content), line, fd));
}
