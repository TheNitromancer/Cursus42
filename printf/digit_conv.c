/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:19:49 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/04 18:08:30 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int static	separator(char *ret, t_flags flags, int inplen)
{
	int		i;
	char	padding;

	i = 0;
	padding = ' ';
	if (flags.zero && !flags.dash)
		padding = '0';
	while (flags.minfw-- > (unsigned int) inplen)
		ret[i++] = padding;
	return (i);
}

int static	signature(char *ret, char c, t_flags flags)
{
	if (flags.plus && c != '-')
	{
		*ret = '+';
		return (1);
	}
	if (flags.spc && c != '-')
	{
		*ret = ' ';
		return (1);
	}
	if (c == '-')
		return (1);
	return (0);
}

char	*ptf_digit(t_flags flags, va_list list)
{
	char	*ret;
	char	*temp;
	int		inplen;
	int		hassign;
	int		i;

	temp = ptf_itoa(va_arg(list, int));
	if (!temp)
		return (NULL);
	inplen = ptf_strlen(temp);
	hassign = 0;
	if (flags.spc || flags.plus)
		hassign = 1;
	if (flags.minfw < (unsigned int) inplen + hassign)
		flags.minfw = inplen;
	ret = ptf_zalloc(flags.minfw + hassign);
	if (!ret)
		return (NULL);
	i = 0;
	if (!flags.dash)
		i = separator(ret, flags, inplen);
	i += signature(&ret[i], *temp, flags);
	while (flags.pcsn-- > (unsigned int) inplen)
		ret[i++] = '0';
	while (*temp)
		ret[i++] = *temp++;
	if (flags.dash)
		separator(&ret[i], flags, inplen);
	free (temp - inplen);
	return (ret);
}

// SEPARADOR // SIGNO/ESPACIO // RELLENO DE PCS // NUM // SEPARADOR
