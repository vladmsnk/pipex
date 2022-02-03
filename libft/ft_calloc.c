/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:06:13 by jjhezane          #+#    #+#             */
/*   Updated: 2021/10/18 19:06:14 by jjhezane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*to_out;

	to_out = (void *)malloc(count * size);
	if (to_out == NULL)
		return (NULL);
	ft_bzero(to_out, count * size);
	return (to_out);
}
