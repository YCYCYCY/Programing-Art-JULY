/*一个台阶总共有n 级，如果一次可以跳1 级，也可以跳2 级。

求总共有多少总跳法，并分析算法的时间复杂度。
        /  1                             n = 1
f(n)=      2                             n = 2
        \  f(n-1) + f(n-2)               n > 2


*/
//递归
long long Fibonacci(unsigned int n)
{
    int result[3] = {0, 1, 2};
    if (n <= 2)
        return result[n];

    return Fibonacci(n - 1) + Fibonacci(n - 2);
}
//非递归
int ClimbStairs(int n)
{
    int dp[3] = { 1, 1 };
    if (n < 2)
    {
        return 1;
    }
    for (int i = 2; i <= n; i++)
    {
        dp[2] = dp[0] + dp[1];
        dp[0] = dp[1];
        dp[1] = dp[2];
    }
    return dp[2];
}

/*
换硬币问题。

想兑换100元钱，有1,2,5,10四种钱，问总共有多少兑换方法。
arr[j]=arr[j-1]+arr[j-2]+arr[j-5]+arr[j-10]
*/