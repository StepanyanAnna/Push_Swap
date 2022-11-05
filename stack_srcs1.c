/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annstepa <annstepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 19:13:53 by edgghaza          #+#    #+#             */
/*   Updated: 2022/09/27 20:11:14 by annstepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*new_stack_element(int value)
{
	t_stack	*temp;

	temp = (t_stack *)malloc(sizeof(t_stack));
	if (!temp)
		return (NULL);
	temp->value = value;
	temp->a_score = -1;
	temp->a_r_score = -1;
	temp->b_score = -1;
	temp->b_r_score = -1;
	temp->rank = -1;
	temp->next = NULL;
	return (temp);
}

void	minus_plus_search(char **argv, int i, int *array)
{
	while (argv[++i])
	{
		if (!ft_strcmp(argv[i], "-" ) || !ft_strcmp(argv[i], "+"))
		{
			ft_putstr_fd("Error\n", 2);
			exit(0);
		}
		array[i] = ft_atoi(argv[i]);
	}
}

t_stack	*stack_initialization(int argc, char **argv)
{
	int			i;
	t_stack		*head;

	i = 0;
	head = NULL;
	while (i < argc)
	{
		add_back_stack(&head, new_stack_element(ft_atoi(argv[i])));
		i++;
	}
	return (head);
}

int	stack_size(t_stack *stack)
{
	if (stack == NULL)
		return (0);
	else
		return (1 + stack_size(stack->next));
}

void	free_stack(t_stack **stack_a)
{
	t_stack	*temp;

	while (*stack_a)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(temp);
		temp = NULL;
	}
}
