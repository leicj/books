// 大小为N的数组A,其主要元素是一个出现次数超过N/2的元素.
// 可通过以下算法计算出主要元素
// 首先,找出主要元素的一个候选元.这个候选元是唯一有可能是主要元素的元素.第二步确定是否该候选元
// 实际上就是主要元素.我们构造第二个数组B.一一比较A1和A2,如果相等,则放入B中.
// 然后递归对B执行相同的操作,直到找到最后一个元素.

#include <stdio.h>
#include <limits.h>

int func(int A[], int B[], int len)
{
    int i = 0;
    int index = 0;

    for (i = 0; i < len / 2; i++) {
        if (A[i * 2] == A[i * 2 + 1]) {
            B[index++] = A[i * 2];
        }
    }
    // 当数组为奇数时,将最后一个数放进B中
    if (len % 2) {
        if (index == 0) {
            return A[len - 1];
        }
        for (i = 0; i < index; i++) {
            if (B[i] == A[len - 1]) {
                B[index++] = A[len - 1];
                break;
            }
        }
    }

    if (0 == index) {
        return INT_MIN;
    } else if (1 == index) {
        return B[0];
    } else {
        return func(B, A, index);
    }
}

int main(void)
{
    int arr[] = {3, 3, 4, 4, 3, 3, 4, 4, 5};
    int B[9];
    int num = 0;

    num = func(arr, B, 9);

    printf("%d\n", num);

    return 0;
}
