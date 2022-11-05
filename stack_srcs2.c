/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annstepa <annstepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 19:23:41 by edgghaza          #+#    #+#             */
/*   Updated: 2022/09/27 20:05:30 by annstepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_lastelement(t_stack *head)
{
	if (head == NULL)
		return (NULL);
	if (head->next == NULL)
		return (head);
	else
		return (stack_lastelement(head->next));
}

void	add_back_stack(t_stack **stack, t_stack *new_item)
{
	t_stack	*temp;

	if (*stack == NULL)
		*stack = new_item;
	else
	{
		temp = stack_lastelement(*stack);
		temp->next = new_item;
	}
}

void	print_stack(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}
}

t_stack	*before_stack_lastelement(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	if (stack->next == NULL)
		return (NULL);
	if (stack->next->next == NULL)
		return (stack);
	else
		return (before_stack_lastelement(stack->next));
}

void	add_front_stack(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}
