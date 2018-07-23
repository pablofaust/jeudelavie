/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_of_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 17:57:46 by pfaust            #+#    #+#             */
/*   Updated: 2018/03/20 18:16:39 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_max_of_3(int x, int y, int z)
{
	if (x >= y && x >= y)
		return (x);
	else if (y > x && y >= z)
		return (y);
	else
		return (z);
}