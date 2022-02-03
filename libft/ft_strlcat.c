/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:08:38 by jjhezane          #+#    #+#             */
/*   Updated: 2021/10/18 19:08:39 by jjhezane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		dst_len;
	char		*dst_tmp;

	dst_tmp = dst;
	dst_len = ft_strlen((const char *)dst);
	if (dstsize < dst_len)
		dst_len = dstsize;
	dst_tmp += dst_len;
	if (dstsize - dst_len == 0)
		return (dst_len + ft_strlen(src));
	return (dst_len + ft_strlcpy(dst_tmp, src, dstsize - dst_len));
}
