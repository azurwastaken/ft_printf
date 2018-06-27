#include "lib_printf.h"

char	*ft_strfreedup(char *src)
{
	char *mem_alloc;

	if (!(mem_alloc = (char *)malloc(sizeof(*src) * (ft_strlen(src) + 1))))
		return (0);
	mem_alloc = ft_strcpy(mem_alloc, src);
	free(src);
	return (mem_alloc);
}
