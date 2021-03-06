/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobbin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 07:30:51 by trobbin           #+#    #+#             */
/*   Updated: 2019/11/05 18:00:41 by trobbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H
# define BUFF_SIZE 512
# define FD_SIZE 1024
# include "libft/libft.h"

int ft_readline(char **buffer, char **line, int fd);
int	get_next_line(const int fd, char **line);

#endif
