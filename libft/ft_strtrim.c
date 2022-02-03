/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:09:10 by jjhezane          #+#    #+#             */
/*   Updated: 2021/10/22 15:49:56 by jjhezane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	begin;
	unsigned int	end;

	if (s1 && set)
	{
		begin = 0;
		end = ft_strlen(s1);
		while (s1[begin] != '\0' && ft_strchr(set, s1[begin]))
			begin++;
		while (end && ft_strchr(set, s1[end]))
			end--;
		return (ft_substr(s1, begin, end - begin + 1));
	}
	return (NULL);
}
