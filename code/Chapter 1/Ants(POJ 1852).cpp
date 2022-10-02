#include<iostream>
using namespace std;

const int N = 1e6 + 10;
int a[N];

// 题目的描述：两只蚂蚁碰见之后就会掉头反向而行，这是一个思维屏障
// 其实对于问题的解决，完全可以认为两只蚂蚁可以穿过继续前行
// 所以对于左边的区间（以l的中点作为区间的分界点），选出一个距离右端点最远的点
// 对于右边区间，选出离左端点最远的点即可
int lmax = N, rmax = -N;
int min_ans = -N;

int main()
{
    int t;
    cin >> t;

    while (t --)
    {
        int l, n;
        cin >> l >> n;

        for (int i = 0; i < n; i ++)
        {
            scanf("%d", &a[i]);

            // 求最大时间只需要取得数据中的最大值，最小值，然后选择前往离自己更远的端点即可
            // 即比较(l - lmax)：靠左的蚂蚁到右端点的距离 和 rmax靠右的蚂蚁到左端点的距离的大小
            lmax = min(lmax, a[i]);
            rmax = max(rmax, a[i]);

            // min(a[i],l-a[i])的意思是，选择去往离自己更近的端点
            // 再将结果同min_ans取一个max的意思是：对所有的最小距离取一个最大值
            // 这个最大值就是使得所有蚂蚁落下杆子的最小时间
            min_ans = max(min_ans, min(a[i], l - a[i])); 
        }

        int max_ans = (l - lmax) > rmax? (l - lmax):rmax;
        cout << min_ans << ' ' << max_ans << endl;

        lmax = N, rmax = -N, min_ans = -N; // 重置标志，准备下一次case
    }
    

    return 0;
}