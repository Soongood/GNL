/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobbin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 19:08:17 by trobbin           #+#    #+#             */
/*   Updated: 2019/10/14 19:35:33 by trobbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_freeptr(void *pointer)
{
	free(pointer);
	pointer = NULL;
}

void		*ft_realloc(void *ptr, size_t size)
{
	void		*p;
	void		*temp;
	size_t		length;

	if (!ptr)
		return (ptr = ft_memalloc(size));
	if (!size && ptr)
	{
		ft_freeptr(ptr);
		return(ptr);
	}
	if (p = ft_memalloc(size))
	{
		length = (ft_strlen((const char *)ptr) >= size) ? size : (ft_strlen((const char *)ptr) + 1);
		temp = ft_memcpy(p, ptr, length);
		ft_freeptr(ptr);
		return (temp);
	}
	return (NULL);
}
