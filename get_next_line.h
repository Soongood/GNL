/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobbin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 07:30:51 by trobbin           #+#    #+#             */
/*   Updated: 2019/11/01 17:01:05 by trobbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H

# include "libft/libft.h"

# define BUFF_SIZE 512
# define GNL_OK 1
# define GNL_EOF 0
# define GNL_ERROR -1

typedef struct	s_gnl
{
	struct s_gnl    *next;
	char		    *content;
	int			    fd;
}				    t_gnl;
int	get_next_line(const int fd, char **line);

#endif
