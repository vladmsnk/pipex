/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:08:20 by jjhezane          #+#    #+#             */
/*   Updated: 2021/10/22 16:38:53 by jjhezane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_words(char const *s, char c)
{
	unsigned int	count;
	unsigned int	iter;

	count = 0;
	iter = 0;
	while (s[iter] != '\0')
	{
		if (s[iter] != c && (s[iter + 1] == c || s[iter + 1] == '\0'))
			count++;
		iter++;
	}
	return (count);
}

static char	**clear(char **splitted, unsigned int n)
{
	unsigned int	iter;

	iter = 0;
	if (n > 0)
	{
		while (iter < n)
			free(splitted[iter++]);
	}
	free(splitted);
	return (NULL);
}

static char	**get_words(char **splitted, char const *s, char c)
{
	int				bgn;
	unsigned int	iter;
	unsigned int	n;

	bgn = -1;
	n = 0;
	iter = 0;
	while (iter <= ft_strlen(s))
	{
		if (s[iter] != c && bgn == -1)
			bgn = iter;
		else if (bgn != -1 && (s[iter] == c || s[iter] == '\0'))
		{
			*(splitted + n) = (char *)malloc(sizeof(char) * (iter - bgn + 1));
			if (!(*(splitted + n)))
				return (clear(splitted, n));
			ft_strlcpy(*(splitted + n), s + bgn, iter - bgn + 1);
			bgn = -1;
			n++;
		}
		iter++;
	}
	*(splitted + n) = NULL;
	return (splitted);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;

	if (!s)
		return (NULL);
	splitted = (char **)malloc((sizeof(char *) * (count_words(s, c) + 1)));
	if (!splitted)
		return (NULL);
	return (get_words(splitted, s, c));
}
