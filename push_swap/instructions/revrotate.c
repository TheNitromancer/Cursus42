/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:54:15 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/07/21 11:01:08 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void static	ps_revrotate(t_stack *stack)
{
	int	temp;
	int	i;

	i = stack->top - 1;
	temp = stack->stk[i];
	while (i > 0)
	{
		stack->stk[i] = stack->stk[i - 1];
		i--;
	}
	stack->stk[i] = temp;
}

void	ps_rra(t_stack *a)
{
	ps_revrotate(a);
	write(1, "rra\n", 4);
}

void	ps_rrb(t_stack *b)
{
	ps_revrotate(b);
	write(1, "rrb\n", 4);
}

void	ps_rrr(t_stack *a, t_stack *b)
{
	ps_revrotate(a);
	ps_revrotate(b);
	write(1, "rrr\n", 4);
}
