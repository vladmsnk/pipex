/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:05:59 by jjhezane          #+#    #+#             */
/*   Updated: 2021/10/20 15:35:26 by jjhezane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	with_zeros(int *minus_cnt, int *plus_cnt, int *iter, int *nmbr)
{
	*minus_cnt = 0;
	*plus_cnt = 0;
	*iter = 0;
	*nmbr = 0;
}

int	ft_atoi(const char *str)
{
	int		minus_cnt;
	int		plus_cnt;
	int		iter;
	int		nmbr;

	with_zeros(&minus_cnt, &plus_cnt, &iter, &nmbr);
	while (str[iter] == ' ' || (str[iter] >= '\t' && str[iter] <= '\r'))
		iter++;
	while (str[iter] == '-' || str[iter] == '+')
	{
		if (str[iter] == '-')
			minus_cnt++;
		else if (str[iter] == '+')
			plus_cnt++;
		iter++;
	}
	if ((minus_cnt >= 1 && plus_cnt >= 1) || (minus_cnt > 1 || plus_cnt > 1))
		return (nmbr);
	while (str[iter] >= '0' && str[iter] <= '9')
		nmbr = nmbr * 10 + (str[iter++] - 48);
	if (minus_cnt == 1)
		return (-1 * nmbr);
	return (nmbr);
}
