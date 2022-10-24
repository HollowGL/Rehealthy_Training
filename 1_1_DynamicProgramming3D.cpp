// refer: https://github.com/zlysm/MyExercise/blob/main/maxSumOfSubMatrix.cpp

#include <iostream>


// 二维DP问题解法，求数组的最大子序和：找出连续几个数的和的最大值
int maxSumOfRow(int* arr, int len) {
    int max = -10000;
    int sub[len];
    sub[0] = arr[0];
    for (int i = 1; i < len; i++) {
        sub[i] = sub[i - 1] > 0 ? (sub[i - 1] + arr[i]) : arr[i];  //上一个数大于0则加上，否则从当前数开始
        max = max > sub[i] ? max : sub[i];
    }
    return max;
}

int main() {

    int n, m;
    int maxSum = -10000;
    int maxSumOfTemp;
    std::cin >> n >> m;
    int** num = new int*[n];
    for (int i = 0; i < n; i++) {
        num[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> num[i][j];
            num[i][j] += (i == 0 ? 0 : num[i - 1][j]);  // 将前i行的数组全部累加到第i行
        }
    }

    // 将三维DP转化为二维DP进行处理   
    for (int i = 0; i < n; i++) {
        for (int k = i; k < n; k++) {
            int temp[m];
            for (int j = 0; j < m; j++) {
                temp[j] = num[k][j] - (i > 0 ? num[i - 1][j] : 0);
            }
            maxSumOfTemp = maxSumOfRow(temp, m);
            maxSum = maxSum > maxSumOfTemp ? maxSum : maxSumOfTemp;
        }
    }

    std::cout << maxSum << std::endl;

    for (int i = 0; i < n; i++)
        delete num[i];
    delete[] num;

    return 0;
}