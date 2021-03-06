/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:00:14 by pfaust            #+#    #+#             */
/*   Updated: 2018/03/20 18:17:18 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_rgb_to_hex(int r, int g, int b)
{
	unsigned int hex;

	hex = (r << 16) + (g << 8) + b;
	return (hex);
}
