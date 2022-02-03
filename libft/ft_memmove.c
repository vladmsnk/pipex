/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:24:56 by jjhezane          #+#    #+#             */
/*   Updated: 2021/10/18 19:25:40 by jjhezane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*tmp_src;
	char		*tmp_dest;		

	tmp_dest = (char *) dst;
	tmp_src = (char *) src;
	i = 0;
	if (tmp_dest > tmp_src)
	{
		tmp_dest += len;
		tmp_src += len;
		i = len;
		while (i > 0)
		{
			*--tmp_dest = *--tmp_src;
			i--;
		}
		return (dst);
	}
	ft_memcpy(dst, src, len);
	return (dst);
}
