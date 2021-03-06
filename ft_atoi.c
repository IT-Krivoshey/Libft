/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstaunto <jstaunto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:52:20 by jstaunto          #+#    #+#             */
/*   Updated: 2020/08/25 13:52:20 by jstaunto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *str)
{
	int						i;
	long long				res;
	long long				x;
	int						sign;

	x = (long long)(LLONG_MAX / 10);
	i = 0;
	res = 0;
	sign = 1;
	while (ft_isallwspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		str[i++] == '-' ? sign = -1 : 0;
	while (ft_isdigit(str[i]))
	{
		if ((res > x || (res == x && (str[i] - '0') > 7)) && sign == 1)
			return (-1);
		else if ((res > x || (res == x && (str[i] - '0') > 8)) && sign == -1)
			return (0);
		res = res * 10 + (str[i++] - 48);
	}
	return (sign * res);
}
