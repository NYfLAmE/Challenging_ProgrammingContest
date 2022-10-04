#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int n;
bool flag[110];
vector<int> a;

void dfs(int x)
{
    if (x == n)
    {
        // for (int i = 0; i < a.size(); i ++)
        // {
        //     cout << a[i] << ' ';
        // }
        // cout << endl;
        cout << endl;
        return;
    }
    
    for (int i = 1; i <= n; i ++)
    {
        // 为什么前面少了个数字?
        // 其实当前的输出就很好的展示了递归调用的过程
        // 当调用完毕之后，会直接跳到下一个数字，所有前面少了数字
        // 以我目前的水平，除了用vector将调用过程中的数字push_back和pop_back之外，貌似找不到什么解决方案
        if (flag[i] == false)
        {
            cout << i << ' ';
            // a.push_back(i);
            flag[i] = true;
            dfs(x +  1);
            flag[i] = false;
            // a.pop_back();
        }
    }
    
}
int main()
{
    cin >> n;
    
    dfs(0); // 里面的形参表示当前已经输出了多少个数字
    
    return 0;
}