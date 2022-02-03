/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:08:48 by jjhezane          #+#    #+#             */
/*   Updated: 2021/10/22 15:48:16 by jjhezane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mapped;
	unsigned int	iter;
	size_t			len;

	mapped = NULL;
	if (s)
	{
		len = ft_strlen((const char *)s) + 1;
		mapped = (char *)malloc(sizeof(char) * len);
		if (!mapped)
			return (NULL);
		iter = 0;
		while (s[iter] != '\0')
		{
			mapped[iter] = f(iter, (char)s[iter]);
			iter++;
		}
		mapped[iter] = '\0';
	}
	return (mapped);
}
