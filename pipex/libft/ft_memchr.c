/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:01:42 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/03 09:45:47 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*temp;
	unsigned char		val;

	temp = s;
	val = c;
	while (n--)
	{
		if (*temp == val)
			return ((unsigned char *)temp);
		temp++;
	}
	return (0);
}
