#include "stack_manager.h"

int main(int argc, char *argv[])
{
	int	data;
	int	digit_len;
	t_stack	a;
	t_stack	b;

	data = 0;
	digit_len = 0;
	create_stack(&a);
	create_stack(&b);
	if (argc < 2)
		return (0);
	input_error(argc, argv, &a, &digit_len);
	if (!overlap_check(argc, argv, digit_len))
	{
		printf("Error\n");
		return (1);
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

// 숫자가 아닌 문자 처리
void	input_error(int argc, char *argv[], t_stack *a, int *digit_len)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
			add_split_digit(argv, a, i, digit_len);
		else
		{
			if (!is_str_digit(argv[i]))
			{
				printf("Error\n");
				exit(1);
			}
			add_back(a, ft_atoi(argv[i]));
			(*digit_len)++;
		}
		i++;
	}
}

void	add_split_digit(char *argv[], t_stack *a, int i, int *digit_len)
{
	int		j;
	char	**split_input;

	j = 0;
	split_input = 0;
	split_input = ft_split(argv[i], ' ');
	if (split_input[0] == 0)
	{
		printf("Error\n");
		exit(1);
	}
	while (split_input[j])
	{
		if (!is_str_digit(split_input[j]))
		{
			printf("Error\n");
			exit(1);
		}
		add_back(a, ft_atoi(split_input[j]));
		(*digit_len)++;
		j++;
	}
	free_split(split_input);
}

void	add_arr_digit(char *argv[], int i, int *index, int *arr)
{
	int		j;
	char	**split_input;

	j = 0;
	split_input = 0;
	split_input = ft_split(argv[i], ' ');
	while (split_input[j])
	{
		arr[(*index)] = ft_atoi(split_input[j]);
		(*index)++;
		j++;
	}
	free_split(split_input);
}

int	is_str_digit(const char *s)
{
	// +, -, 숫자만
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!(s[i] >= '0' && s[i] <= '9'))
		return (0);
	while(s[i] >= '0' && s[i] <= '9')
	{
		if(!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		i++; 
	}
	if(!(s[i] >= '0' && s[i] <= '9') && s[i] != 0)
		return (0);
	return (1);
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