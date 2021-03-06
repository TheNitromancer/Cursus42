/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:58:15 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/11 10:55:31 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char		*revs;
	unsigned char	temp;

	temp = c;
	revs = s + ft_strlen(s);
	while (revs >= s)
	{
		if (*revs == temp)
			return ((char *)revs);
		revs--;
	}
	return (0);
}
