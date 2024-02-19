#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array.
 * @x: First integer to swap.
 * @y: Second integer to swap.
*/
void swap_ints(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using Selection Sort Algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
*/
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t m, n;

	if (array == NULL || size < 2)
		return;

	for (m = 0; m < size - 1; m++)
	{
		min = array + m;
		for (n = m + 1; n < size; n++)
			min = (array[n] < *min) ? (array + n) : min;

		if ((array + n) != min)
		{
			swap_ints(array + m, min);
			print_array(array, size);
		}
	}
}
