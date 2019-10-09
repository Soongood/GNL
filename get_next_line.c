/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobbin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:41:57 by trobbin           #+#    #+#             */
/*   Updated: 2019/10/09 22:31:15 by trobbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

char *ft_readline(char *buffer)
{
	while (*buffer)
	{

	}
}

int get_next_line(const int fd, char **line)
{
	static char	*buf[FD_SETSIZE];
	int		count;
	int		bytes;

	if (fd >= FD_SETSIZE || fd < 0 || !line)
		return (-1);
	if (buf[fd])
		//read
	while ((bytes = read(fd, buf, BUFF_SIZE)))
	{
		ft_realloc();
	}
}
