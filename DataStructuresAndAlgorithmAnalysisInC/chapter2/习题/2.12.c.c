// 求最大子序列乘积
// 需要用两个变量保存包括当前位置序列的最大乘积和最小乘积，
// 然后还需要比较两次，一次是最大乘积和最小乘积是否需要互换，还有一次是不是只选当前位置就是最好的
// 参考自网上代码:
// http://blog.csdn.net/sunmenggmail/article/details/8120330

#include <stdio.h>

double maxMulti(double v[], int n) {
    double maxt = 1;
    double mint = 1;
    double maxv = v[0];

    for(int i = 0; i < n; ++i) {
        if(v[i] == 0) {
            maxt = 1;
            mint = 1;
            if (v[i] > maxv)
                maxv = 0;
        }
        else{
            double oriMint = mint;
            double oriMaxt = maxt;

            double minrst = mint * v[i];
            double maxrst = maxt * v[i];

            maxt = maxrst > minrst ?maxrst: minrst;
            mint  = maxrst > minrst ? minrst : maxrst;

            if (maxt < v[i])
                maxt = v[i];
            if (mint > v[i])
                mint = v[i];

            if (maxv < maxt)
                maxv = maxt;
        }
    }
    return maxv;
}

int main(void)
{
    double arr[] = {-2, 3, 0.5, 4, -1.0 / 3, -2};
    double arr1[] = {-2, -1, -3, -4, -5, 6};
    double sum = 1;

    sum = maxMulti(arr, 6);
    printf("min positive sum is: %f\n", sum);

    sum = 1;

    sum = maxMulti(arr1, 6);

    printf("min positive sum is: %f\n", sum);

    return 0;
}
