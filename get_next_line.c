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

int	ft_readline(char *buffer)
{
	int shift;
	
	shift = 0;
	while (buffer[shift] != '\n')
		if (!buffer[shift++])
			return (0);
	ft_reallocate((buffer + shift), ft_strlen(buffer) - shift);
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
		//read and write to line (function)
	temp = 0;
	while ((bytes = read(fd, buf, BUFF_SIZE)))
	{
		temp += bytes;
		buf[fd] = ft_reallocate(buf, temp);
	}
	//read and write to line (function)
	return (0);
}
