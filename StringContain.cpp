/*
给定两个分别由字母组成的字符串A和字符串B，字符串B的长度比字符串A短。
请问，如何最快地判断字符串B中所有字母是否都在字符串A里？
*/

//方法一、质数对应法
/*
让每个字母与一个素数对应，从2开始，往后类推，A对应2，B对应3，C对应5，......。
遍历第一个字串，把每个字母对应素数相乘。最终会得到一个整数。
如果用第一串字符串求出的整数能整除第二串字符串的整数，说明第二个字符串是第一个的子集
*/
//此方法只有理论意义，因为整数乘积很大，有溢出风险
bool StringContain(string &a,string &b)
{
    const int p[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59,61, 67, 71, 73, 79, 83, 89, 97, 101};
    int f = 1;
    for (int i = 0; i < a.length(); ++i)
    {
        int x = p[a[i] - 'A'];
        if (f % x)
        {
            f *= x;
        }
    }
    for (int i = 0; i < b.length(); ++i)
    {
        int x = p[b[i] - 'A'];
        if (f % x)
        {
            return false;
        }
    }
    return true;
}


//方法二
/*
把26个字母用一个32位的整形hash中的26位来标识，
如若包含C，则i整形中的第('C'-'A')位为1，否则为0；
然后用第二个字符串中的每一位去并&hash，若结果为0，则不含包
*/
// 时间复杂度O(n + m)，空间复杂度O(1)
bool StringContain(string &a,string &b)
{
    int hash = 0;
    for (int i = 0; i < a.length(); ++i)
    {
        hash |= (1 << (a[i] - 'A'));
    }
    for (int i = 0; i < b.length(); ++i)
    {
        if ((hash & (1 << (b[i] - 'A'))) == 0)
        {
            return false;
        }
    }
    return true;
}