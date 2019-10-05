#include "libft.h"

void	*ft_reallocate(void *ptr, size_t size)
{
	void		*p;
	void		*temp;
	size_t		length;

	if (!ptr)
		return (ptr = ft_memalloc(size));
	if (!size && ptr)
			free(ptr);
	else
	{
		if (p = ft_memalloc(size))
		{
			length = (ft_strlen((const char *)ptr) >= size) ? size : ft_strlen((const char *)ptr);
			temp = ft_memcpy(p, ptr, length);
			return (temp);
		}
	}
	return (NULL);
}
