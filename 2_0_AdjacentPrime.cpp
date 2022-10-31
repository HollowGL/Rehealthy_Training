#include <iostream>
#include <cmath>
using namespace std;


bool debug = false;


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
    
    int num[20000] = {0};             // 都初始化为素数，数组长度超过1000000时会报错
    fun(num, 20000);

    int T, r, t;
    cin >> T >> r;
    bool* hasAP = new bool[T];           // 一个存放真假的数组，检验第n个数是否有毗邻的素数
    for (int i = 0; i < T; i++)          // 都初始化为false
        hasAP[i] = false;

    for (int j = 0; j < T; j++) {
        cin >> t;
        for (int i = (t - r > 0 ? t - r : 0); i <= t + r; i++) {
            if (!num[i] && i != t)
                hasAP[j] = true;
        }
    }

    for (int i = 0; i < T; i++) {
        if (hasAP[i])
            cout << 'T' << endl;
        else
            cout << 'F' << endl;
    }


    // 以下内容仅在debug为真时执行，用于找bug
    if (debug) {
        for (int i = 0; i < 2000; i++) {
            cout << num[i];
        }
    }

    return 0;   
}
