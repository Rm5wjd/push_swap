#include "stack_manager.h"

void	print_stack(const t_stack *sp)
{
	t_stacknode	*cur;

	if (!sp)
		return ;
	cur = sp->head->next;
	while (cur != sp->tail)
	{
		printf("%d\n", cur->data);
		cur = cur->next;
	}
}

void	destroy_stack(t_stack *sp)
{
	t_stacknode	*cur;
	t_stacknode	*temp;

	if (!sp)
		return ;
	cur = sp->head->next;
	while (cur != sp->tail)
	{
		temp = cur;
		cur = cur->next;
		free(temp);
	}
	free(sp->head);
	free(sp->tail);
}


int	is_stack_empty(t_stack *sp)
{
	t_stacknode	*temp;
	int			count;

	temp = sp->head->next;
	count = 0;
	while (temp != sp->tail)
	{
		temp = temp->next;
		count++;
		if (count > 0)
			return (0);
	}
	return (1);
}
