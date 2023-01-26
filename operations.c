#include "stack_manager.h"

void	swap_a_or_b(t_stack *sp)
{
	t_stacknode	*cur;
	t_stacknode	*next;
	int			temp;

	cur = sp->head->next;
	next = cur->next;
	temp = 0;
	if (cur == sp->tail || next == sp->tail)
		return ;
	temp = cur->data;
	cur->data = next->data;
	next->data = temp;
	temp = cur->index;
	cur->index = next->index;
	next->index = cur->index;
}

void	push_a_or_b(t_stack *to, t_stack *from)
{
	int	data;

	data = 0;
	if (is_stack_empty(from))
		return ;
	data = from->head->next->data;
	delete_front(from);
	node_index_down(from);
	add_front(to, data, -1);
	node_index_up(to);
}

void	rotate_a_or_b(t_stack *sp)
{
	int	data;

	data = 0 ;
	if (is_stack_empty(sp))
		return ;
	data = sp->head->next->data;
	delete_front(sp);
	node_index_down(sp);
	add_back(sp, data, sp->len);
}

void	reverse_a_or_b(t_stack *sp)
{
	int	data;

	data = 0 ;
	if (is_stack_empty(sp))
		return ;
	data = sp->tail->prev->data;
	delete_back(sp);
	node_index_up(sp);
	add_front(sp, data, 0);
}
