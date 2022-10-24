// 效率极低，容易超时

#include <iostream>
using namespace std;


int len(int x)
{
    int res = 0;
    for (int i = 1; i <= x; i++)
    {
        res += i;
    }
    return res;
}

int main()
{
    int n, m;
    int n_Maxlen, m_Maxlen;

    cin >> n >> m;
    n_Maxlen = len(n);
    m_Maxlen = len(m);

    // int w[n][m];
    // int w_all[n_Maxlen * m_Maxlen]; // 所有矩形的个数

    int **w = new int *[n];
    int *w_all = new int[n_Maxlen * m_Maxlen];
    for (int i = 0; i < n; ++i)
        w[i] = new int[m];

    // 输入每个正方形的收益
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> w[i][j];
        }
    }

    int global_i = 0;           // w_all的索引值
    for (int i = 0; i < n; i++) // 遍历行数
    {
        for (int j = 0; j < m; j++) // 遍历列数
        {
            for (int n_Rec = 1; n_Rec <= n - i; n_Rec++) // 遍历矩形长度
            {
                for (int m_Rec = 1; m_Rec <= m - j; m_Rec++) // 遍历矩形宽度
                {
                    // 计算一个左上顶点在(i, j)，长宽为n_Reclen和m_Reclen的矩形的收益
                    int w_rec = 0;
                    for (int in = i; in < i + n_Rec; in++)
                    {
                        for (int jm = j; jm < j + m_Rec; jm++)
                        {
                            w_rec += w[in][jm];
                        }
                    }
                    w_all[global_i] = w_rec;
                    global_i += 1;
                }
            }
        }
    }

    // 找出最大收益
    int max_w = w_all[0]; // 先随便给它赋个值
    for (int i = 0; i < n_Maxlen * m_Maxlen; i++)
    {
        if (max_w < w_all[i])
        {
            max_w = w_all[i];
        }
    }
    cout << max_w;

    return 0;
}