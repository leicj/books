#include <stdio.h>

int main(void)
{
    int arr[] ={5,2,4,6,1,3};
    int len = 6;
    int i = 0, j = 0;
    int key;
    for (j = 1; j < len; j++) {
        key = arr[j];
        i = j - 1;
        while (i >= 0 && arr[i] > key) {
            arr[i + 1] = arr[i];
            i -= 1;
        }
        arr[i+ 1] = key;
    }

    for (i = 0; i < len; i++) {
         printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
