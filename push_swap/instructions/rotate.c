/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:12:38 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/07/21 10:53:29 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void static	ps_rotate(t_stack *stack)
{
	int	temp;
	int	lim;
	int	i;

	i = 0;
	lim = stack->top - 1;
	temp = stack->stk[0];
	while (i < lim)
	{
		stack->stk[i] = stack->stk[i + 1];
		i++;
	}
	stack->stk[i] = temp;
}

void	ps_ra(t_stack *a)
{
	ps_rotate(a);
	write(1, "ra\n", 3);
}

void	ps_rb(t_stack *b)
{
	ps_rotate(b);
	write(1, "rb\n", 3);
}

void	ps_rr(t_stack *a, t_stack *b)
{
	ps_rotate(a);
	ps_rotate(b);
	write(1, "rr\n", 3);
}
