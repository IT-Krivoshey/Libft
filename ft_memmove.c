/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstaunto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:36:21 by jstaunto          #+#    #+#             */
/*   Updated: 2019/09/16 21:17:00 by jstaunto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	i = -1;
	if (dst > src)
		while (n-- > 0)
			*(s1 + n) = *(s2 + n);
	else
		while (++i < n)
			*(s1 + i) = *(s2 + i);
	return (dst);
}
