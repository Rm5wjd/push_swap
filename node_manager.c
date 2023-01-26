#include "stack_manager.h"

int	create_stack(t_stack *sp)
{
	if (!sp)
		return (0);
	sp->head = (t_stacknode *)malloc(sizeof(t_stacknode));
	if (!(sp->head))
		return (0);
	sp->tail = (t_stacknode *)malloc(sizeof(t_stacknode));
	if (!(sp->tail))
		return (0);
	sp->head->data = 0;
	sp->head->index = -1;
	ft_bzero(&sp->head->ops, sizeof(sp->head->ops));
	sp->tail->data = 0;
	sp->tail->index = -1;
	ft_bzero(&sp->tail->ops, sizeof(sp->tail->ops));
	sp->head->prev = sp->head;
	sp->head->next = sp->tail;
	sp->tail->prev = sp->head;
	sp->tail->next = sp->tail;
	sp->len = 0;
	return (1);
}

void	add_front(t_stack *sp, int data, int index)
{
	t_stacknode	*node;
	t_stacknode	*head_node;

	if (!sp)
		return ;
	node = (t_stacknode *)malloc(sizeof(t_stacknode));
	head_node = sp->head;
	node->data = data;
	node->index = index;
	node->prev = head_node;
	node->next = head_node->next;
	head_node->next->prev = node;
	head_node->next = node;
	(sp->len)++;
}

void	add_back(t_stack *sp, int data, int index)
{
	t_stacknode	*node;
	t_stacknode	*tail_node;

	if (!sp)
		return ;
	node = (t_stacknode *)malloc(sizeof(t_stacknode));
	tail_node = sp->tail;
	node->data = data;
	node->index = index;
	node->next = tail_node;
	node->prev = tail_node->prev;
	tail_node->prev->next = node;
	tail_node->prev = node;
	(sp->len)++;
}

void	delete_front(t_stack *sp)
{
	t_stacknode	*temp;
	t_stacknode	*head_node;

	if (!sp)
		return ;
	if (is_stack_empty(sp))
		return ;
	head_node = sp->head;
	temp = head_node->next;
	temp->next->prev = head_node;
	head_node->next = temp->next;
	free(temp);
	(sp->len)--;
}

void	delete_back(t_stack *sp)
{
	t_stacknode	*temp;
	t_stacknode	*tail_node;

	if (!sp)
		return ;
	tail_node = sp->tail;
	temp = tail_node->prev;
	temp->prev->next = tail_node;
	tail_node->prev = temp->prev;
	free(temp);
	(sp->len)--;
}
