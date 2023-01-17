#include "stack_manager.h"

int main(int argc, char *argv[])
{
	int	data;
	int	i;
	t_stack	a;
	t_stack	b;

	data = 0;
	i = 1;
	create_stack(&a);
	create_stack(&b);
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		data = ft_atoi(argv[i]);
		add_back(&a, data);
		i++;
	}
	read_stdin(&a, &b);
	if (sort_check(&a, &b))
		printf("OK\n");
	else
		printf("KO\n");
	printf("-----stack a-----\n");
	print_stack(&a);
	printf("-----stack b-----\n");
	print_stack(&b);
	return (0);
}

// stdin함수
void	read_stdin(t_stack *a, t_stack *b)
{
	char	*buf;
	
	buf = get_next_line(0);
	while (buf)
	{
		instruction_check(buf, a, b);
		buf = get_next_line(0);
	}
}

// instruction check 함수
void	instruction_check(char *buf, t_stack *a, t_stack *b)
{
	if (ft_strncmp("sa\n", buf, 3) == 0)
		swap_a_or_b(a);
	else if (ft_strncmp("sb\n", buf, 3) == 0)
		swap_a_or_b(b);
	else if (ft_strncmp("ss\n", buf, 3) == 0)
	{
		swap_a_or_b(a);
		swap_a_or_b(b);
	}
	else if (ft_strncmp("pa\n", buf, 3) == 0)
		push_a_or_b(a, b);
	else if (ft_strncmp("pb\n", buf, 3) == 0)
		push_a_or_b(b, a);
	else if (ft_strncmp("ra\n", buf, 3) == 0)
		rotate_a_or_b(a);
	else if (ft_strncmp("rb\n", buf, 3) == 0)
		rotate_a_or_b(b);
	else if (ft_strncmp("rr\n", buf, 3) == 0)
	{
		rotate_a_or_b(a);
		rotate_a_or_b(b);
	}
	else if (ft_strncmp("rra\n", buf, 4) == 0)
		reverse_a_or_b(a);
	else if (ft_strncmp("rrb\n", buf, 4) == 0)
		reverse_a_or_b(b);
	else if (ft_strncmp("rrr\n", buf, 4) == 0)
	{
		reverse_a_or_b(a);
		reverse_a_or_b(b);
	}
}
// a, b 정렬 확인 함수
int	sort_check(t_stack *a, t_stack *b)
{
	t_stacknode	*head_node;
	int			data;
	int			temp;

	head_node = a->head->next;
	data = 0;
	temp = 0;
	while (head_node->next != a->tail)
	{
		data = head_node->data;
		temp = head_node->next->data;
		if (temp < data)
			return (0);
		head_node = head_node->next;
	}
	if (!is_stack_empty(b))
		return (0);
	return (1);
}