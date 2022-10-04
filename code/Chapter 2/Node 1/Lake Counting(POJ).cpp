#include<iostream>
using namespace std;

const int N = 110;
char chart[N][N];

int n, m;
int res;

void dfs(int i, int j)
{
    chart[i][j] = '.'; // 直接将'W'修改成'.';

    // 遍历所有方向
    for (int x = -1; x <= 1; x ++)
    {
        for (int y = -1; y <= 1; y ++)
        {
            if (i + x > 0 && i + x <= n && j + y > 0 && j + y <= m && chart[i + x][j + y] != '.')
            dfs(i + x, j + y);
        }
    }

    // 遍历了所有的方向之后，结束调用返回即可
    return;
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= m; j ++)
        {
            cin >> chart[i][j];
        }
    }

    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= m; j ++)
        {
            if (chart[i][j] == 'W')
            {
                dfs(i, j);
                res ++;
            }
        }
    }

    cout << res << endl;
    return 0;
}