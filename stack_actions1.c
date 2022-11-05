/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annstepa <annstepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:34:52 by edgghaza          #+#    #+#             */
/*   Updated: 2022/09/27 18:56:33 by annstepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_action(t_stack **head)
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
		ft_putstr_fd("sa\n", 1);
	}
}

void	pa_action(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*p;
	t_stack	*k;

	if (*stack_b)
	{
		p = *stack_a;
		k = *stack_b;
		(*stack_b) = (*stack_b)->next;
		(*stack_a) = k;
		(*stack_a)->next = p;
		ft_putstr_fd("pa\n", 1);
	}
}

void	ra_action(t_stack **head)
{
	t_stack	*temp;

	if (*head && (*head)->next)
	{
		temp = *head;
		*head = (*head)->next;
		temp->next = NULL;
		add_back_stack(head, temp);
		ft_putstr_fd("ra\n", 1);
	}
}

void	pb_action(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*p;
	t_stack	*k;

	if (*stack_a)
	{
		p = *stack_b;
		k = *stack_a;
		(*stack_a) = (*stack_a)->next;
		(*stack_b) = k;
		(*stack_b)->next = p;
		ft_putstr_fd("pb\n", 1);
	}
}

void	rb_action(t_stack **head)
{
	t_stack	*temp;

	if (*head && (*head)->next)
	{
		temp = *head;
		*head = (*head)->next;
		temp->next = NULL;
		add_back_stack(head, temp);
		ft_putstr_fd("rb\n", 1);
	}
}
