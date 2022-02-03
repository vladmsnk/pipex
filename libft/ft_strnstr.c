/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:09:02 by jjhezane          #+#    #+#             */
/*   Updated: 2021/10/19 13:25:46 by jjhezane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	iter1;

	iter1 = 0;
	if (ft_strlen(needle) != 0)
	{
		while (haystack[iter1] != '\0' && iter1 < len)
		{
			if (ft_strncmp(haystack + iter1, needle, ft_strlen(needle)) == 0 && \
			(len - iter1 >= ft_strlen(needle)))
			{
				return ((char *)(haystack + iter1));
			}
			iter1++;
		}
		return (NULL);
	}
	return ((char *)haystack);
}
