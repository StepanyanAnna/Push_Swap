/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annstepa <annstepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:49:03 by edgghaza          #+#    #+#             */
/*   Updated: 2022/09/27 19:00:45 by annstepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb_action(t_stack **head)
{
	t_stack	*temp;
	t_stack	*next;

	temp = *head;
	if (*head && (*head)->next)
	{
		next = (*head)->next;
		(*head)->next = next->next;
		next->next = temp;
		(*head) = next;
		ft_putstr_fd("sb\n", 1);
	}
}

void	ss_action(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*next;
	int		flag;

	flag = 0;
	temp = *stack_a;
	if (*stack_a && (*stack_a)->next)
	{
		next = (*stack_a)->next;
		(*stack_a)->next = next->next;
		next->next = temp;
		(*stack_a) = next;
		flag = 1;
	}
	temp = *stack_b;
	if (*stack_b && (*stack_b)->next)
	{
		next = (*stack_b)->next;
		(*stack_b)->next = next->next;
		next->next = temp;
		(*stack_b) = next;
		flag += 2;
	}
}
