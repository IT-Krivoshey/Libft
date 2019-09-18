/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstaunto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 12:46:34 by jstaunto          #+#    #+#             */
/*   Updated: 2019/09/17 17:08:07 by jstaunto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wrdlen(char const *str, char c)
{
	size_t	sz;
	int		i;

	sz = 0;
	i = 0;
	while (*str)
	{
		if (!i && *str != c)
			sz++;
		i = (*str == c) ? 0 : 1;
		str++;
	}
	return (sz);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**new;
	size_t	idx;
	size_t	widx;
	size_t	inw;
	size_t	bg;

	if (!s)
		return (NULL);
	if (!(new = (char **)ft_memalloc(sizeof(char *) * (wrdlen(s, c) + 1))))
		return (NULL);
	idx = -1;
	widx = 0;
	inw = 0;
	bg = 0;
	while (s[++idx])
	{
		if (inw && s[idx] == c)
			new[widx++] = ft_strsub(s, bg, idx - bg);
		if (!inw && s[idx] != c)
			bg = idx;
		inw = (s[idx] == c) ? 0 : 1;
	}
	if (inw)
		new[widx] = ft_strsub(s, bg, idx - bg);
	return (new);
}
