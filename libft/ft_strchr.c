/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:08:24 by jjhezane          #+#    #+#             */
/*   Updated: 2021/10/18 19:08:25 by jjhezane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	iter;
	char	*to_out;

	iter = 0;
	while (*(s + iter) != '\0' && *(s + iter) != (char)c)
		iter++;
	if (*(s + iter) == (char)c)
	{
		to_out = (char *)(s + iter);
		return (to_out);
	}
	return (NULL);
}
