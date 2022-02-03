/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:08:27 by jjhezane          #+#    #+#             */
/*   Updated: 2021/10/18 19:08:28 by jjhezane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*str_to_dup;

	len = ft_strlen(s1);
	str_to_dup = (char *)malloc((len + 1) * sizeof(char));
	if (str_to_dup == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(str_to_dup, s1, len + 1);
	return (str_to_dup);
}
