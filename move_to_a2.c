/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_a2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annstepa <annstepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:34:24 by edgghaza          #+#    #+#             */
/*   Updated: 2022/09/27 19:49:51 by annstepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	total_score_element2(int result, t_stack *head, int *transfertype)
{
	if (head->b_score + head->a_r_score < result)
	{
		result = head->b_score + head->a_r_score;
		*transfertype = 5;
	}
	if (head->b_r_score + head->a_score < result)
	{
		result = head->b_r_score + head->a_score;
		*transfertype = 6;
	}
	return (result);
}

static int	total_score_element(t_stack *head, int *transfertype)
{
	int	result;
	int	biggest_r_score;

	result = head->b_score;
	*transfertype = 1;
	if (head->a_score >= head->b_score)
	{
		result = head->a_score;
		*transfertype = 2;
	}
	biggest_r_score = head->a_r_score;
	if (head->b_r_score > biggest_r_score)
		biggest_r_score = head->b_r_score;
	if (result > biggest_r_score)
	{
		result = biggest_r_score;
		if (head->b_r_score > head->a_r_score)
			*transfertype = 3;
		else
			*transfertype = 4;
	}
	result = total_score_element2(result, head, transfertype);
	return (result);
}

t_stack	*make_decision(t_stack *head, int *transfertype)
{
	t_stack	*pin;
	int		best_total_score;
	int		best_rank;
	int		best_transfer_type;

	best_total_score = total_score_element(head, transfertype);
	best_rank = head->rank;
	best_transfer_type = *transfertype;
	pin = head;
	while (head)
	{
		if (total_score_element(head, transfertype) < best_total_score
			|| (total_score_element(head, transfertype) == best_total_score
				&& head->rank >= best_rank))
		{
			best_total_score = total_score_element(head, transfertype);
			best_rank = head->rank;
			best_transfer_type = *transfertype;
		}
		head = head->next;
	}
	*transfertype = best_transfer_type;
	while (pin->rank != best_rank)
		pin = pin->next;
	return (pin);
}

void	process_decision2(t_stack **stack_a, t_stack **stack_b,
		t_stack *item, int *transfertype)
{
	if (*transfertype == 4)
	{
		while (item->b_r_score-- > 0 && item->a_r_score--)
			rrr_action(stack_a, stack_b);
		while (item->a_r_score-- > 0)
			rra_action(stack_a);
	}
	if (*transfertype == 5)
	{
		while (item->b_score-- > 0)
			rb_action(stack_b);
		while (item->a_r_score-- > 0)
			rra_action(stack_a);
	}
	if (*transfertype == 6)
	{
		while (item->b_r_score-- > 0)
			rrb_action(stack_b);
		while (item->a_score-- > 0)
			ra_action(stack_a);
	}
}

void	process_decision(t_stack **stack_a, t_stack **stack_b,
		t_stack *item, int *transfertype)
{
	if (*transfertype == 1)
	{
		while (item->a_score-- > 0 && item->b_score--)
			rr_action(stack_a, stack_b);
		while (item->b_score-- > 0)
			rb_action(stack_b);
	}
	if (*transfertype == 2)
	{
		while (item->b_score-- > 0 && item->a_score--)
			rr_action(stack_a, stack_b);
		while (item->a_score-- > 0)
			ra_action(stack_a);
	}
	if (*transfertype == 3)
	{
		while (item->a_r_score-- > 0 && item->b_r_score--)
			rrr_action(stack_a, stack_b);
		while (item->b_r_score-- > 0)
			rrb_action(stack_b);
	}
	if (*transfertype > 3)
		process_decision2(stack_a, stack_b, item, transfertype);
	pa_action(stack_a, stack_b);
}
