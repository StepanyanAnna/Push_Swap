/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorHandlings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annstepa <annstepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:43:09 by annstepa          #+#    #+#             */
/*   Updated: 2022/09/27 21:07:31 by annstepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	over_int_bound(char *c)
{
	long long int	s;

	if (ft_strlen(c) > 11)
		return (1);
	s = ft_atoi(c);
	if (s > 2147483647 || s < -2147483648)
		return (1);
	return (0);
}

static int	not_digit(char *c)
{
	while (*c && ft_isspace(*c))
		c++;
	if (*c == '-' || *c == '+')
		c++;
	while (*c)
	{
		if (ft_isdigit(*c) != 1)
			return (1);
		c++;
	}
	return (0);
}

char	*argv_string(int argc, char **argv)
{
	char	*str;
	char	*temp;
	char	*a;
	int		i;

	i = 0;
	str = NULL;
	while (++i < argc)
	{
		a = ft_strjoin(argv[i], " ");
		temp = str;
		str = ft_strjoin(str, a);
		free(temp);
		free(a);
	}
	return (str);
}

static int	not_similar(char **argv)
{
	int	i;
	int	j;
	int	flag;
	int	*arr;

	flag = 0;
	arr = (int *)malloc(sizeof(int) * (splited_size(argv)));
	if (!arr)
		return (1);
	i = -1;
	minus_plus_search(argv, i, arr);
	while (argv[++i])
	{
		j = i;
		while (++j < splited_size(argv))
			if (arr[i] == arr[j])
				flag = 1;
	}
	free(arr);
	arr = NULL;
	return (flag);
}

int	non_valid_args(int argc, char **argv)
{
	int	i;
	int	error;

	error = 0;
	i = 0;
	while (i < argc)
	{
		error = not_digit(argv[i]);
		if (error > 0)
			return (error);
		error = over_int_bound(argv[i]);
		if (error > 0)
			return (error);
		i++;
	}
	error = not_similar(argv);
	return (error);
}
