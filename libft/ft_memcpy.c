/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:07:51 by jjhezane          #+#    #+#             */
/*   Updated: 2021/10/18 19:07:52 by jjhezane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*tmp_src;
	char	*tmp_dest;

	if (dst == NULL && src == NULL && n > 0)
	{
		return (NULL);
	}
	tmp_src = (char *)src;
	tmp_dest = (char *)dst;
	while (n--)
	{
		*tmp_dest = *tmp_src;
		tmp_dest++;
		tmp_src++;
	}
	return (dst);
}
