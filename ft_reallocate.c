#include "libft.h"

static	void	ft_freeptr(void *pointer)
{
	free(pointer);
	pointer = NULL;
}

void		*ft_reallocate(void *ptr, size_t size)
{
	void		*p;
	void		*temp;
	size_t		length;

	if (!ptr)
		return (ptr = ft_memalloc(size));
	if (!size && ptr)
		return(ft_freeptr(ptr));
	if (p = ft_memalloc(size))
	{
		length = (ft_strlen((const char *)ptr) >= size) ? size : ft_strlen((const char *)ptr);
		temp = ft_memcpy(p, ptr, length);
		ft_freeptr(ptr);
		return (temp);
	}
	return (NULL);
}
