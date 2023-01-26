#include "stack_manager.h"

void	partitioning(t_stack *a, t_stack *b, int digit_len, int *arr)
{
	int			pivot_a;
	int			pivot_b;
	t_stacknode	*a_headnode;

	pivot_a = arr[digit_len / 3];
	pivot_b = arr[(digit_len / 3) * 2];
	a_headnode = a->head->next;
	while (a_headnode != a->tail)
	{
		if (a_headnode->data > pivot_a && a_headnode <= pivot_b)
			push_a_or_b(b, a);
		else if (a_headnode <= pivot_a)
		{
			push_a_or_b(b, a);
			rotate_a_or_b(b);
		}
		else
			rotate_a_or_b(a);
		a_headnode = a_headnode->next;
	}
	a_headnode = a->head->next;
	while (a_headnode != a->tail)
		push_a_or_b(b, a);
}

void	rb_rrb_calc(t_stack *b, t_stacknode *b_node)
{
	if (b_node->index <= (b->len / 2))
	{
		b_node->ops->rb = b_node->index;
		b_node->ops->rrb = 0;
	}
	else
	{
		b_node->ops->rrb = b->len - b_node->index;
		b_node->ops->rb = 0;
	}
}

void	op_calc(t_stack * b, t_stacknode *b_node, int top, int bot)
{
	if (top == 1)
	{
		b_node->ops->sa = 1;
		b_node->ops->ra = 0;
		b_node->ops->rra = 0;
		rb_rrb_calc(b, b_node);
	}
	else if (top >= bot)
	{
		b_node->ops->ra = top;
		b_node->ops->rra = top;
		b_node->ops->sa = 0;
		rb_rrb_calc(b, b_node);
	}
	else
	{
		if (top == 0)
		{
			b_node->ops->rra = 0;
			b_node->ops->ra = 0;
			b_node->ops->sa = 0;
		}
		b_node->ops->rra = bot;
		b_node->ops->ra = bot + 1;
		b_node->ops->sa = 0;
		rb_rrb_calc(b, b_node);
	}
	b_node->ops->sum = b_node->ops->ra + b_node->ops->rra + \
	b_node->ops->rb + b_node->ops->rrb + b_node->ops->sa;
}

t_stacknode	*priority_calc(t_stack *b)
{
	t_stacknode	*b_head;
	t_stacknode	*min_op_node;

	min_op_node = b->head->next;
	b_head = b->head->next;
	while (b_head != b->tail)
	{
		if (b_head->ops->sum < min_op_node->ops->sum)
			min_op_node = b_head;
		b_head = b_head->next;
	}
	return (min_op_node);
}

t_stacknode	*greedy_op_calc(t_stack *a, t_stack *b)
{
	int			top;
	int			bot;
	t_stacknode	*a_head;
	t_stacknode	*b_head;

	b_head = b->head->next;
	while (b_head != b->tail)
	{
		top = 0;
		bot = 0;
		a_head = a->head->next;
		while (a_head != a->tail)
		{
			if (a->head < b->head)
				top++;
			else
				bot++;
			a->head = a->head->next;
		}
		op_calc(b, b_head, top, bot);	
		b_head = b_head->next;
	}
	return (priority_calc(b));
}

void	greedy(t_stack *a, t_stack *b)
{
	int			i;
	t_stacknode	*min_op_node;

	i = 0;
	while (b->len != 0)
	{
		min_op_node = greedy_op_calc(a, b);
		while (i++ < min_op_node->ops->rb)
			rotate_a_or_b(b);
		i = 0;
		while (i++ < min_op_node->ops->rrb)
			reverse_a_or_b(b);
		i = 0;
		if (min_op_node->ops->ra > min_op_node->ops->rra) // bot > top
		{
			while (i++ < min_op_node->ops->rra)
				reverse_a_or_b(a);
			i = 0;
			push_a_or_b(a, b);
			while (i++ < min_op_node->ops->ra)
				rotate_a_or_b(a);
			i = 0;
			while (i++ < min_op_node->ops->sa)
				swap_a_or_b(a);
		}
		else // top >= bot
		{
			while (i++ < min_op_node->ops->ra)
				rotate_a_or_b(a);
			i = 0;
			push_a_or_b(a, b);
			while (i++ < min_op_node->ops->rra)
				reverse_a_or_b(a);
			i = 0;
			while (i++ < min_op_node->ops->sa)
				swap_a_or_b(a);
		}
	}
}