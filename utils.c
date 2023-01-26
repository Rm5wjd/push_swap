#include "stack_manager.h"

void	free_split(char **split_str)
{
	int	i;

	i = 0;
	while (split_str[i])
	{
		free(split_str[i]);
		i++;
	}
	free(split_str);
}

void	node_index_down(t_stack *a_or_b)
{
	t_stacknode	*head_node;

	head_node = a_or_b->head->next;
	while(head_node != a_or_b->tail)
	{
		(head_node->index)--;
		head_node = head_node->next;
	}
}

void	node_index_up(t_stack *a_or_b)
{
	t_stacknode	*head_node;

	head_node = a_or_b->head->next;
	while(head_node != a_or_b->tail)
	{
		(head_node->index)++;
		head_node = head_node->next;
	}
}