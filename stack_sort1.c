/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annstepa <annstepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:53:33 by edgghaza          #+#    #+#             */
/*   Updated: 2022/10/04 18:34:15 by annstepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	not_presorted_stack(t_stack *head)
{
	t_stack	*temp;
	int		flag;

	flag = 0;
	temp = head;
	while (head && head->next)
	{
		if (head->value > head->next->value && flag)
			return (1);
		if (head->value > head->next->value)
			flag = 1;
		head = head->next;
	}
	if (head && head->value > temp->value && flag)
		return (1);
	return (0);
}

void	three_size_stack_presort(t_stack **head)
{
	int	size;
	int	first;
	int	second;
	int	third;

	size = stack_size(*head);
	if (size == 3)
	{
		first = (*head)->value;
		second = (*head)->next->value;
		third = (*head)->next->next->value;
		if (second > third && second > first && first < third)
			sa_action(head);
		if (third > first && third > second && first > second)
			sa_action(head);
		if (first > second && first > third && second > third)
			sa_action(head);
	}
}

t_stack	*fill_stack_b(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		min;
	int		max;
	int		med;
	int		size;

	if (min_max_med_search(stack_a, &min, &max, &med) > 0)
		return (NULL);
	stack_b = NULL;
	size = stack_size(*stack_a);
	while (size > 3)
	{
		if ((*stack_a)->value == min || (*stack_a)->value == med
			|| (*stack_a)->value == max)
			ra_action(stack_a);
		else
		{
			pb_action(stack_a, &stack_b);
			size--;
		}
	}
	three_size_stack_presort(stack_a);
	return (stack_b);
}

t_stack	*stack_sort(t_stack **stack_a)
{
	t_stack	*stack_b;

	if (is_sorted(*stack_a))
		return (NULL);
	if (not_presorted_stack(*stack_a))
	{
		stack_b = fill_stack_b(stack_a);
		while (stack_b)
			move_to_a(stack_a, &stack_b);
	}
	final_sort(stack_a);
	return (NULL);
}

int	is_sorted(t_stack *head)
{
	t_stack	*temp;

	temp = head;
	if (stack_size(temp) == 1)
		return (1);
	while (temp->next != NULL)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}
