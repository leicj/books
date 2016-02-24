// my_calloc(size_t num_elements, size_t element_size);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *my_calloc(size_t num_elements, size_t element_size)
{
    int *p = malloc(num_elements * element_size);
    int i = 0;
    for (i = 0; i < num_elements; i++) {
        *(p + i) = 0;
    }
    return p;
}

int main(void)
{
    int num_elements = 2;
    int element_size = sizeof(int);
    int *arr = my_calloc(num_elements, element_size);

    printf("%d--%d\n", arr[0], arr[1]);

    return 0;
}
