#include "stack_manager.h"

int	overlap_check(int argc, char *argv[], int digit_len)
{
	int		i;
	int		index;
	int		*arr;

	i = 1;
	index = 0;
	arr = (int *)malloc(sizeof(int) * digit_len);
	if (!arr)
		return (0);
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
			add_arr_digit(argv, i, &index, arr);
		else
			arr[index++] = ft_atoi(argv[i]);
		i++;
	}
	quick_sort(0, digit_len - 1, arr);
	if (!arr_overlap_check(arr, digit_len))
	{
		free(arr);
		return (0);
	}
	free(arr);
	return (1);
}

int	arr_overlap_check(int *arr, int digit_len)
{
	int	i;

	i = 0;
	while (i < digit_len - 1)
	{
		if (arr[i] == arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

void	quick_sort(int left, int right, int *data)
{
	int	pivot;
	int	j;
	int	i;

	pivot = left;
	j = pivot;
	i = left + 1;
	if (left < right)
	{
		while (i <= right)
		{
			if (data[i] < data[pivot])
			{
				j++;
				swap(&data[j], &data[i]);
			}
			i++;
		}
		swap(&data[left], &data[j]);
		pivot = j;
		quick_sort(left, pivot - 1, data);
		quick_sort(pivot + 1, right, data);
	}
}

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