/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annstepa <annstepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 19:47:27 by edgghaza          #+#    #+#             */
/*   Updated: 2022/10/04 18:33:30 by annstepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_error(char **argv)
{
	ft_putstr_fd("Error\n", 2);
	free_split(argv);
	exit(-1);
}

int	main(int argc, char **argv)
{
	char	*str;
	t_stack	*stack_a;

	if (argc == 1)
	{
		sleep(1);
		return (0);
	}
	str = argv_string(argc, argv);
	argv = ft_split(str, ' ');
	free(str);
	if (!argv[0])
		ft_error(argv);
	argc = splited_size(argv);
	if (non_valid_args(argc, argv) > 0)
		ft_error(argv);
	stack_a = stack_initialization(argc, argv);
	stack_sort(&stack_a);
	free_stack(&stack_a);
	free_split(argv);
	return (0);
}
