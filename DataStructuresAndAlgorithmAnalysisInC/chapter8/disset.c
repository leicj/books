// 不相交集合的简单数据实现

#include <stdio.h>

#define SIZE 10

// 初始化
void init(int *arr);
// find
int find(int x, int *arr);
// union
void myunion(int arr[], int x1, int x2);

int main(void)
{
    int arr[SIZE + 1];

    init(arr);

    myunion(arr, 5, 6);
    myunion(arr, 7, 8);
    myunion(arr, 5, 7);

    if (find(6, arr) == find(8, arr)) {
        printf("6 and 8 in same set!\n");
    } else {
        printf("6 and 8 not in same set!\n");
    }
    if (find(6, arr) == find(1, arr)) {
        printf("6 and 1 in same set!\n");
    } else {
        printf("6 and 1 not in same set!\n");
    }

    return 0;
}
// 初始化
void init(int *arr)
{
    int i = 0;

    for (i = SIZE; i > 0; i--) {
        arr[i] = 0;
    }
}
// find
int find(int x, int *arr)
{
    if (arr[x] <= 0) {
        return x;
    } else {
        return find(arr[x], arr);
    }
}
// union
void myunion(int arr[], int x1, int x2)
{
    arr[x2] = x1;
}
