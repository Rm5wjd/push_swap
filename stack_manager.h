# ifndef STACK_MANAGER_H
#define STACK_MANAGER_H

#include <stdlib.h>
#include <stdio.h>
#include "./libft/libft.h"
#include "./libft/get_next_line.h"

typedef struct s_stacknode t_stacknode;
typedef struct s_stack t_stack;
typedef struct s_operations t_op;
struct s_operations
{
	int	rb;
	int	rrb;
	int	ra;
	int	rra;
	int	sa;
	int sum;
};
struct s_stacknode
{
	int			data;
	int			index;
	t_stacknode	*prev;
	t_stacknode	*next;
	t_op		ops;
};
struct s_stack
{
	int			len;
	t_stacknode	*head;
	t_stacknode	*tail;
};

// node_manager
int create_stack(t_stack *sp);
void add_front(t_stack *sp, int data, int index);
void add_back(t_stack *sp, int data, int index);
void delete_front(t_stack *sp);
void delete_back(t_stack *sp);

// staack_manager
int is_stack_empty(t_stack *sp);
void print_stack(const t_stack *sp);
void destroy_stack(t_stack *sp);

// oprations
void	swap_a_or_b(t_stack *sp);
void	push_a_or_b(t_stack *to, t_stack *from);
void	rotate_a_or_b(t_stack *sp);
void	reverse_a_or_b(t_stack *sp);

// sorting
int	*overlap_check(int argc, char *argv[], int digit_len);
int	arr_overlap_check(int *arr, int digit_len);
void	swap(int *a, int *b);
void	quick_sort(int start, int end, int *data);
int	sort_check(t_stack *a, t_stack *b);

// checker
void	input_error(int argc, char *argv[], t_stack *a, int *digit_len);
void	add_split_digit(char *argv[], t_stack *a, int i, int *digit_len);
void	add_arr_digit(char *argv[], int i, int *index, int *arr);
int	is_str_digit(const char *s);

// utils
void	free_split(char **split_str);
void	node_index_down(t_stack *a_or_b);
void	node_index_up(t_stack *a_or_b);
void	rb_rrb_calc(t_stack *b, t_stacknode *b_node);
void	op_calc(t_stack * b, t_stacknode *b_node, int top, int bot);

// greedy
void	partitioning(t_stack *a, t_stack *b, int digit_len, int *arr);
t_stacknode	*priority_calc(t_stack *b);
t_stacknode	*greedy_op_calc(t_stack *a, t_stack *b);
void	greedy(t_stack *a, t_stack *b);
#endif