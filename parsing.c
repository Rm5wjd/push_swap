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
	// 파티셔닝
	// 정렬
	printf("-----stack a-----\n");
	print_stack(&a);
	printf("-----stack b-----\n");
	print_stack(&b);
	return (0);
}