#include <iostream>
#include <cmath>
using namespace std;


// 筛选法求素数
void fun(int a[], int len) {
    int sieve = sqrt(len);               // 筛子的长度不大于数组长度的开方
    for (int i = 2; i < sieve; i++) {    // 从2开始
        for (int j = 2; i * j < len; j++) {
            a[i * j] = 1;                // 赋值1表示筛掉，即为合数
        }
    }
}

int main() {
    
    
}
