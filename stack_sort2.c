/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annstepa <annstepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:14:35 by edgghaza          #+#    #+#             */
/*   Updated: 2022/09/27 21:24:52 by annstepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_array(int *arr, int size, t_stack *head)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < size)
	{
		arr[i] = head->value;
		head = head->next;
	}
	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
		{
			if (arr[i] > arr[j])
			{
				k = arr[i];
				arr[i] = arr[j];
				arr[j] = k;
			}
		}
	}
	return (arr);
}

void	ranking_of_stack(t_stack *head, int *arr)
{
	int	i;

	while (head)
	{
		i = 0;
		while (arr[i] != head->value)
			i++;
		head->rank = i;
		head = head->next;
	}
}

int	min_max_med_search(t_stack **head, int *min, int *max, int *med)
{
	int	size;
	int	*arr;

	size = stack_size(*head);
	arr = (int *)malloc(sizeof(int) * size);
	if (arr == NULL)
		return (1);
	arr = sort_array(arr, size, *head);
	*min = arr[0];
	*max = arr[size - 1];
	*med = arr[size / 2];
	ranking_of_stack(*head, arr);
	free(arr);
	arr = NULL;
	return (0);
}

void	final_sort(t_stack **stack_a)
{
	t_stack		*temp;
	int			min;
	int			max;
	int			steps;
	int			size;

	if (min_max_med_search(stack_a, &min, &max, &steps) > 0)
		return ;
	temp = *stack_a;
	steps = 0;
	while (temp->value != min)
	{
		steps++;
		temp = temp->next;
	}
	size = stack_size(*stack_a);
	if (steps <= size - steps + 1)
		while (!is_sorted(*stack_a))
			ra_action(stack_a);
	else
		while (!is_sorted(*stack_a))
			rra_action(stack_a);
}
