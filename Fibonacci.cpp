/*һ��̨���ܹ���n �������һ�ο�����1 ����Ҳ������2 ����

���ܹ��ж������������������㷨��ʱ�临�Ӷȡ�
        /  1                             n = 1
f(n)=      2                             n = 2
        \  f(n-1) + f(n-2)               n > 2


*/
//�ݹ�
long long Fibonacci(unsigned int n)
{
    int result[3] = {0, 1, 2};
    if (n <= 2)
        return result[n];

    return Fibonacci(n - 1) + Fibonacci(n - 2);
}
//�ǵݹ�
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
��Ӳ�����⡣

��һ�100ԪǮ����1,2,5,10����Ǯ�����ܹ��ж��ٶһ�������
arr[j]=arr[j-1]+arr[j-2]+arr[j-5]+arr[j-10]
*/