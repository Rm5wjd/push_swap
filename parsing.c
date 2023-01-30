#include "stack_manager.h"

int main(int argc, char *argv[])
{
	int	digit_len;
	t_stack	a;
	t_stack	b;

	digit_len = 0;
	create_stack(&a);
	create_stack(&b);
	if (argc < 2)
		return (0);
	input_error(argc, argv, &a, &digit_len);
	// printf("input_error check\n");
	// 파티셔닝
	partitioning(&a, &b, digit_len, overlap_check(argc, argv, digit_len));
	// printf("partitioning complete\n");
	// 정렬
	greedy(&a, &b);
	printf("-----stack a-----\n");
	print_stack(&a);
	printf("-----stack b-----\n");
	print_stack(&b);
	return (0);
}