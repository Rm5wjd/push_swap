# ifndef STACK_MANAGER_H
#define STACK_MANAGER_H

#include <stdlib.h>
#include <stdio.h>
#include "./libft/libft.h"
#include "./libft/get_next_line/get_next_line.h"

typedef struct s_stacknode t_stacknode;
typedef struct s_stack t_stack;
struct s_stacknode
{
	int			data;
	t_stacknode	*prev;
	t_stacknode	*next;
};
struct s_stack
{
	t_stacknode	*head;
	t_stacknode	*tail;
};

// node_manager
int create_stack(t_stack *sp);
void add_front(t_stack *sp, int data);
void add_back(t_stack *sp, int data);
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

//main
void	read_stdin(t_stack *a, t_stack *b);
void	instruction_check(char *buf, t_stack *a, t_stack *b);
int	sort_check(t_stack *a, t_stack *b);
int	is_str_digit(const char *s);
void	input_error(int argc, char *argv[], t_stack *a, int *digit_len);
void	add_split_digit(char *argv[], t_stack *a, int i, int *digit_len);

int	overlap_check(int argc, char *argv[], int digit_len);
int	arr_overlap_check(int *arr, int digit_len);
void	swap(int *a, int *b);
void	quick_sort(int left, int right, int *data);
void	add_arr_digit(char *argv[], int i, int *index, int *arr);

// free_util
void	free_split(char **split_str);
#endif