#include <stdio.h>

int main(void)
{
    int arr[] = {5,2,4,6,1,3};
    int len = 6;
    int key = arr[0];
    int index = 0;
    int i = 0, j = 0;

    for (i = 0; i < len - 1; i++) {
        key = arr[i];
        index = i;
        for (j = i + 1; j < len; j++) {
            if (arr[j] < key) {
                key = arr[j];
                index = j;
            }
        }
        arr[index] = arr[i];
        arr[i] = key;
    }

    for (i = 0; i < len; i++) {
         printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
