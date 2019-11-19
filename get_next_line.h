/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobbin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 07:30:51 by trobbin           #+#    #+#             */
/*   Updated: 2019/11/19 06:05:35 by trobbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"

# define BUFF_SIZE 2056
# define FD_SIZE 1024
# define GNL_EOF 0
# define GNL_ERROR -1
# define GNL_OK 1

int		get_next_line(const int fd, char **line);

#endif
