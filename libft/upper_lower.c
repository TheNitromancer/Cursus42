/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upper_lower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:34:11 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/04/22 20:05:27 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
