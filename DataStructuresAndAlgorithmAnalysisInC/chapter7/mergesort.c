// 归并排序

#include <stdio.h>
#include <stdlib.h>

void msort(int A[], int tmpA[], int left, int right);
void mymergesort(int A[], int N);
void merge(int A[], int tmpA[], int lpos, int rpos, int rightend);

int main(void)
{
    int arr[] = {4, 3, 2, 6, 3, 8, 7, 9, 0, 1};

    mymergesort(arr, 10);

    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


void msort(int A[], int tmpA[], int left, int right)
{
    int center;
    if (left < right) {
        center = (left + right) / 2;
        msort(A, tmpA, left, center);
        msort(A, tmpA, center + 1, right);
        merge(A, tmpA, left, center + 1, right);
    }
}
void mymergesort(int A[], int N)
{
    int *tmpA = malloc(N * sizeof(int));
    if (NULL != tmpA) {
        msort(A, tmpA, 0, N - 1);
        free(tmpA);
    } else {
        printf("no space for tmp array!");
    }
}
void merge(int A[], int tmpA[], int lpos, int rpos, int rightend)
{
    int i, leftend, numelements, tmppos;

    leftend = rpos - 1;
    tmppos = lpos;
    numelements = rightend - lpos + 1;

    while (lpos <= leftend && rpos <= rightend) {
        if (A[lpos] <= A[rpos]) {
            tmpA[tmppos++] = A[lpos++];
        } else {
            tmpA[tmppos++] = A[rpos++];
        }
    }

    while (lpos <= leftend) {
        tmpA[tmppos++] = A[lpos++];
    }
    while (rpos <= rightend) {
        tmpA[tmppos++] = A[rpos++];
    }

    for (i = 0; i < numelements; i++, rightend--) {
        A[rightend] = tmpA[rightend];
    }
}
