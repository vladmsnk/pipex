/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:09:06 by jjhezane          #+#    #+#             */
/*   Updated: 2021/10/18 19:09:07 by jjhezane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	iter;
	char	*to_out;

	iter = ft_strlen(s);
	while (iter != 0 && s[iter] != (char)c)
	{
		iter--;
	}
	if (s[iter] == (char)c)
	{
		to_out = (char *)(s + iter);
		return (to_out);
	}
	return (NULL);
}
