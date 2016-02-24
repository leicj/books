#include <stdio.h>
#include <stdlib.h>

void MERGE(int A[], int p,int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int i = 0, j = 0, k = 0;

    int *L = malloc(n1);
    int *R = malloc(n2);

    printf("L:");
    for (i = 0; i < n1; i++) {
        L[i] = A[p + i];
        printf("%d ", L[i]);
    }
    printf("R:");
    for (i = 0; i < n2; i++) {
        R[i] = A[q + i + 1];
        printf("%d ", R[i]);
    }

    i = j = 0;
    for (k = p; k <= r; k++) {
        if (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                A[k] = L[i];
                i += 1;
            } else {
                A[k] = R[j];
                j += 1;
            }
        } else {
            for (; i < n1; i++) {
                 A[k] = L[i];
            }
            for (; j < n2; j++) {
                A[k] = R[j];
            }
        }
    }
}

void MERGESORT(int A[], int p, int r)
{
    int q = 0;
    if (p < r) {
        q = (p + r) / 2;
        MERGESORT(A, p, q);
        MERGESORT(A, q + 1, r);
        MERGE(A, p, q, r);
    }
}

int main(void)
{
    int arr[] = {5, 2, 4, 7, 1, 3, 2, 6};
    int len = 8;
    int i = 0;

    MERGESORT(arr, 0, len - 1);

    printf("\n");
    for (i = 0; i < len; i++) {
         printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
