/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_functions1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgghaza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:28:49 by edgghaza          #+#    #+#             */
/*   Updated: 2022/07/31 12:59:00 by edgghaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
		write(fd, s, ft_strlen(s));
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	char	*a;
	char	*res;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (len + 1));
	res = p;
	a = s1;
	if (p == NULL)
		return (NULL);
	while (s1 && *s1)
		*p++ = *s1++;
	while (*s2)
		*p++ = *s2++;
	*p = '\0';
	return (res);
}

void	free_split(char **store)
{
	int	i;

	i = 0;
	while (store[i])
	{
		free(store[i]);
		store[i] = NULL;
		i++;
	}
	free(store);
}

int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0') & (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
