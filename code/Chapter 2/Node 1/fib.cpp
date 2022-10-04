// 用斐波拉契来练手递归
// 什么是记忆化搜索，动态规划的思想是什么？

// 使用记忆化搜索的效率是未使用时的800倍

#include<iostream>
using namespace std;

const int N = 1e5 + 10;
long long a[N];

long long OPfib(long long n)
{
    if (n <= 1) return n;
    if (a[n] != 0) return a[n]; // 如果之前已经计算过了，直接返回计算出来的结果
    return a[n] = fib(n - 1) + fib(n - 2); // 否则进行计算并保存以及返回计算结果
}

long long fib(long long n)
{
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    long long n;
    cin >> n;

    cout << fib(n) << endl;
}