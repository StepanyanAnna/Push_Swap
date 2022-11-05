/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_a1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annstepa <annstepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:21:25 by edgghaza          #+#    #+#             */
/*   Updated: 2022/09/27 20:04:33 by annstepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	b_stack_scoring(t_stack *stack_b)
{
	int	size;
	int	i;

	size = stack_size(stack_b);
	i = 0;
	while (stack_b)
	{
		stack_b->b_score = i;
		stack_b->b_r_score = size - i;
		i++;
		stack_b = stack_b->next;
	}
}

static void	a_stack_scoring(t_stack *stack_a, t_stack *stack_b)
{
	t_stack		*pin;
	int			size;
	int			i;
	int			prev;

	size = stack_size(stack_a);
	pin = stack_a;
	while (stack_b)
	{
		stack_a = pin;
		i = 0;
		prev = stack_lastelement(stack_a)->value;
		while (stack_a)
		{
			if (stack_b->value > prev && stack_b->value < stack_a->value)
			{
				stack_b->a_score = i;
				stack_b->a_r_score = size - i;
			}
			i++;
			prev = stack_a->value;
			stack_a = stack_a->next;
		}
		stack_b = stack_b->next;
	}
}

void	move_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*best_rank_element;
	int			ttype;

	b_stack_scoring(*stack_b);
	a_stack_scoring(*stack_a, *stack_b);
	best_rank_element = make_decision(*stack_b, &ttype);
	process_decision(stack_a, stack_b, best_rank_element, &ttype);
}
