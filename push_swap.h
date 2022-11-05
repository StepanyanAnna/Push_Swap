/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annstepa <annstepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:45:34 by edgghaza          #+#    #+#             */
/*   Updated: 2022/10/04 18:33:13 by annstepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	struct s_stack	*next;
	int				value;
	int				a_score;
	int				a_r_score;
	int				b_score;
	int				b_r_score;
	int				rank;
}	t_stack;

//libft_functions
void			free_split(char **store);
size_t			ft_strlen(const char *str);
void			ft_putstr_fd(char *s, int fd);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strjoin(char *s1, char *s2);

//error_handlind
char			*argv_string(int argc, char **argv);
int				non_valid_args(int argc, char **argv);

//stack_srcs1
int				stack_size(t_stack *stack);
void			free_stack(t_stack **stack_a);
t_stack			*stack_initialization(int argc, char **argv);
void			minus_plus_search(char **argv, int i, int *arr);

//stack_srcs2
void			print_stack(t_stack *stack);
t_stack			*stack_lastelement(t_stack *head);
t_stack			*before_stack_lastelement(t_stack *stack);
void			add_front_stack(t_stack **stack, t_stack *new);
void			add_back_stack(t_stack **stack, t_stack *new_item);

//ft_atoi
int				ft_isdigit(int c);
int				ft_isspace(int c);
long long int	ft_atoi(const char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);

//ft_split
int				splited_size(char **words);
char			**ft_split(const char *string, char del);

//stack_action1
void			sa_action(t_stack **head);
void			ra_action(t_stack **head);
void			rb_action(t_stack **head);
void			pb_action(t_stack **stack_a, t_stack **stack_b);
void			pa_action(t_stack **stack_a, t_stack **stack_b);

//stack_action2
void			rra_action(t_stack **head);
void			rrb_action(t_stack **head);
void			rr_action(t_stack **stack_a, t_stack **stack_b);
void			rrr_action(t_stack **stack_a, t_stack **stack_b);

//stack_action3
void			sb_action(t_stack **head);
void			ss_action(t_stack **stack_a, t_stack **stack_b);

//stack_sort1
int				is_sorted(t_stack*head);
int				not_presorted(t_stack *head);
t_stack			*stack_sort(t_stack **stack_a);
t_stack			*fill_stack_b(t_stack **stack_a);
void			three_size_stack_presort(t_stack **head);

//stack_sort2
void			final_sort(t_stack **stack_a);
void			ranking_of_stack(t_stack *head, int *arr);
int				*sort_array(int *arr, int size, t_stack *head);
int				min_max_med_search(t_stack **head, int *min,
					int *max, int *med);
//move_to_a1
void			move_to_a(t_stack **stack_a, t_stack **stack_b);

//move_to_a2
t_stack			*make_decision(t_stack *head, int *tranfertype);
void			process_decision(t_stack **stack_a, t_stack **stack_b,
					t_stack *item, int *tranfertype);

#endif
