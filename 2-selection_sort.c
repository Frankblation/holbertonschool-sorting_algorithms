#include "sort.h"
void selection_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    size_t i, j;
    for (i = 0; i < size - 1; i++)
    {
        size_t min_index = i;

        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_index])
                min_index = j;
        }

        if (min_index != i)
        {
            int temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
        }
    }
}