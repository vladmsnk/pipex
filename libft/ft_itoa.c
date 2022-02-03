/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:06:43 by jjhezane          #+#    #+#             */
/*   Updated: 2021/10/18 19:06:44 by jjhezane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_digts(int n)
{
	unsigned int	cnt;

	if (n < 0)
		n *= -1;
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

static void	parse_int(int n, unsigned int digit_amount, char *str)
{
	unsigned int	iter;

	if (n == 0)
	{
		str[0] = '0';
		iter = 1;
	}
	else
	{
		if (n < 0)
		{
			str[0] = '-';
			iter = 1;
			digit_amount++;
			n *= -1;
		}
		else
			iter = 0;
		while (iter < digit_amount)
		{
			str[iter] = (n / (get_tens(digit_amount - iter - 1))) % 10 + 48;
			iter++;
		}
	}
	str[iter] = '\0';
}

char	*ft_itoa(int n)
{
	unsigned int	digit_amount;
	char			*str;

	digit_amount = count_digts(n);
	if (n < 0)
	{
		str = (char *)malloc((digit_amount + 2) * sizeof(char));
		if (!str)
			return (NULL);
	}
	else if (n > 0)
	{
		str = (char *)malloc((digit_amount + 1) * sizeof(char));
		if (!str)
			return (NULL);
	}
	else
		str = (char *)malloc(2 * sizeof(char));
	parse_int(n, digit_amount, str);
	return (str);
}
