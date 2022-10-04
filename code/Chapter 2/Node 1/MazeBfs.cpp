// BFS 一般用来解决最近，最短相关的问题
// DFS使用的是栈，枚举当前能够到达的所有状态，直到找到答案或者不能继续枚举了为止，返回
// 一提到返回，就需要想到栈，栈可以用来解决当前程序如何返回的问题的

// BFS由近及远枚举状态，所以第一个找到的答案一定是离最初的情况最近的
// 用队列能够很好的实现这个功能：先进先出，由近及远的处理每一个点

#include<iostream>
#include<queue>
using namespace std;

const int N = 110;
int a[N][N];
long long d[N][N];

// 一个点可以有四种转移状态的方式
// 有效数据的下标从1开始
int dirx[5] = {0, -1, 1, 0, 0}, diry[5] = {0, 0, 0, -1, 1};

int n, m;

typedef pair<int, int> P;


void bfs()
{
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= m; j ++)
        {
            d[i][j] = 1e6 + 10;
        }
    }

    queue<P> p;
    p.push({1, 1});
    d[1][1] = 0; // 将起点的d进行初始化

    // 队列为空为止
    while (p.size())
    {
        P tmp = p.front(); // 取出队头开始处理
        p.pop(); // 弹出队头

        for (int i = 1; i <= 4; i ++)
        {
            int nx = tmp.first + dirx[i], ny = tmp.second + diry[i];
            if (nx > 0 && nx <= n && ny > 0 && ny <= m && d[nx][ny] == 1e6 + 10)
            {
                d[nx][ny] = d[tmp.first][tmp.second] + 1;
                p.push({nx, ny});
            }
        }
    }
}
int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= m; j ++)
        {
            cin >> a[i][j];
        }
    }

    bfs();
    cout << d[n][m] << endl;
    return 0;
}

