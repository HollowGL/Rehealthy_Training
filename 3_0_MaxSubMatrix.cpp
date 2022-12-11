#include <iostream>
using namespace std;

int main() {

    int m, n, x, y;           // m行n列
    cin >> m >> n >> x >> y;

    int **num = new int*[m];
    for (int i = 0; i < m; i++) {
        num[i] = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> num[i][j];
        }
    }

    int max = -1000;
    int** sub = new int*[m - x + 1];
    for (int i = 0; i < m - x + 1; i++) {
        sub[i] = new int[n - y + 1];

        for (int j = 0; j < n - y + 1; j++) {
            sub[i][j] = 0;
            for (int k1 = 0; k1 < x; k1++) {
                for (int k2 = 0; k2 < y; k2++) {
                    sub[i][j] += num[i + k1][j + k2];
                }
            }
            if (max < sub[i][j])
                max = sub[i][j];
        }
    }

    cout << max << endl;

    for (int i = 0; i < m; i++)
        delete num[i];
    delete[] num;
    for (int i = 0; i < m - x + 1; i++)
        delete sub[i];
    delete[] sub;

    return 0;
}