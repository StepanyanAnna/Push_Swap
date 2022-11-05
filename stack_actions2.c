/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annstepa <annstepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:39:18 by edgghaza          #+#    #+#             */
/*   Updated: 2022/09/27 21:30:22 by annstepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_action(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		flag;

	flag = 0;
	if (*stack_a && (*stack_a)->next)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = NULL;
		add_back_stack(stack_a, temp);
		flag = 1;
	}
	if (*stack_b && (*stack_b)->next)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		temp->next = NULL;
		add_back_stack(stack_b, temp);
		flag += 2;
	}
	ft_putstr_fd("rr\n", 1);
}

void	rra_action(t_stack **head)
{
	t_stack	*before_last_item;

	if (*head && (*head)->next)
	{
		before_last_item = before_stack_lastelement(*head);
		add_front_stack(head, before_last_item->next);
		before_last_item->next = NULL;
		ft_putstr_fd("rra\n", 1);
	}
}

void	rrb_action(t_stack **head)
{
	t_stack	*before_last_item;

	if (*head && (*head)->next)
	{
		before_last_item = before_stack_lastelement(*head);
		add_front_stack(head, before_last_item->next);
		before_last_item->next = NULL;
		ft_putstr_fd("rrb\n", 1);
	}
}

void	rrr_action(t_stack **head_a, t_stack **head_b)
{
	t_stack	*before_last_item;
	int		flag;

	flag = 0;
	if (*head_a && (*head_a)->next)
	{
		before_last_item = before_stack_lastelement(*head_a);
		add_front_stack(head_a, before_last_item->next);
		before_last_item->next = NULL;
		flag = 1;
	}
	if (*head_b && (*head_b)->next)
	{
		before_last_item = before_stack_lastelement(*head_b);
		add_front_stack(head_b, before_last_item->next);
		before_last_item->next = NULL;
		flag += 2;
	}
	ft_putstr_fd("rrr\n", 1);
}
