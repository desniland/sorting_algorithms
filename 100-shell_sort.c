#include "sort.h"

/**
 * swap - the positions of two elements into an array
 * @array: array
 * @x: array element
 * @y: array element
*/
void swap(int *array, int x, int y)
{

	int tmp;

	tmp = array[x];
	array[x] = array[y];
	array[y] = tmp;
}

/**
 * shell_sort - function that sorts an array of integers in ascending
 *     order using the Shell sort algorithm, using Knuth sequence
 * @size: size of array
 * @array: list with numbers
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, index = 0;

	if (array == NULL || size < 2)
		return;
	while (gap < size / 3)
		gap = 3 * gap + 1;
	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
			for (index = i; index >= gap &&
					(array[index] < array[index - gap]); index -= gap)
				swap(array, index, index - gap);
		print_array(array, size);
		gap /= 3;
	}
}
