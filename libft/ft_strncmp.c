/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:08:58 by jjhezane          #+#    #+#             */
/*   Updated: 2021/10/18 19:08:59 by jjhezane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			iter;
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (unsigned char *)s2;
	iter = 0;
	while (tmp_s1[iter] != '\0' && tmp_s2[iter] != '\0' && iter < n)
	{
		if (tmp_s1[iter] != tmp_s2[iter])
		{
			return ((int)(tmp_s1[iter] - tmp_s2[iter]));
		}
		iter++;
	}
	if (iter == n)
		return (0);
	return ((int)(tmp_s1[iter] - tmp_s2[iter]));
}
