#include <iostream>
using namespace std;

int main() {

    int m, n, x, y;
    cin >> m >> n >> x >> y;

    int **num = new int*[n];
    for (int i = 0; i < n; i++) {
        num[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> num[i][j];
        }
    }

    int **sub = new int*[n - y + 1];
    int max = -1000;
    for (int i = 0; i < m - x + 1; i++) {
        for (int j = 0; j < n - y + 1; j++) {
            sub[i][j] = 0;
            for (int k1 = 0; k1 < x; k1 ++) {
                for (int k2 = 0; k2 < y; k2 ++) {
                    sub[i][j] += num[i + k1][j + k2];
                }
            }
            if (max < sub[i][j])
                max = sub[i][j];
        }
    }

    cout << max << endl;

    for (int i = 0; i < n; i++)
        delete num[i];
    delete[] num;
    for (int i = 0; i < m - x + 1; i++)
        delete sub[i];
    delete[] sub;

    return 0;
}