/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:08:34 by jjhezane          #+#    #+#             */
/*   Updated: 2021/10/22 15:49:08 by jjhezane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	len_s1;
	size_t	len_s2;
	size_t	iter;

	joined = NULL;
	if (s1 && s2)
	{
		len_s1 = ft_strlen(s1);
		len_s2 = ft_strlen(s2);
		iter = 0;
		joined = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
		if (!joined)
			return (NULL);
		while (*s1 || *s2)
		{
			if (*s1)
				*(joined + iter++) = *s1++;
			else if (!(*s1) && *s2)
				*(joined + iter++) = *s2++;
		}
		*(joined + iter++) = '\0';
	}
	return (joined);
}
