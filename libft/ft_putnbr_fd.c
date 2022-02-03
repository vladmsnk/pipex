/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:08:11 by jjhezane          #+#    #+#             */
/*   Updated: 2021/10/22 15:45:31 by jjhezane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_digts(int n)
{
	unsigned int	cnt;

	cnt = 0;
	while (n != 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

static unsigned int	get_tens(int n)
{
	unsigned int	t;
	unsigned int	i;

	i = 0;
	t = 1;
	while ((int)i < n)
	{
		t *= 10;
		i++;
	}
	return (t);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	digits_amount;
	unsigned int	iter;
	char			to_put;

	if (fd >= 0)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n *= -1;
		}
		else if (n == 0)
			ft_putchar_fd('0', fd);
		digits_amount = count_digts(n);
		iter = 0;
		while (iter < digits_amount)
		{
			to_put = (n / (get_tens(digits_amount - iter - 1))) % 10 + 48;
			ft_putchar_fd(to_put, fd);
			iter++;
		}
	}
}
