/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 21:00:44 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/11 13:19:04 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	j;
	size_t	templen;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len)
	{
		j = 0;
		templen = len;
		while (templen && needle[j] && haystack[j] && haystack[j] == needle[j])
		{
			if (!needle[j + 1])
				return ((char *)haystack);
			j++;
			templen--;
			if (templen == 0)
				return (0);
		}
		len--;
		haystack++;
	}
	return (0);
}
