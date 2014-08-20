//两边向中间扫描
bool IsPalindrome(const char *s, int n)
{
    //非法输入
    if (s == NULL || n < 1) 
        return false;   
    char *front, *back;

    //初始化头指针和尾指针
    front = s; 
    back = s + n - 1; 

    while (front < back) 
    {
        if (*front != *back)
            return false; // 不是回文，立即返回  
        ++front;
        --back;
    }
    return true; // 是回文  
}


//中间向两边扫描
bool IsPalindrome2(const char *s, int n)
{
    if (s == NULL || n < 1) 
        return false; // 非法输入  
    char *first, *second;

    int m = ((n >> 1) - 1) >= 0 ? (n >> 1) - 1 : 0; // m is themiddle point of s      
    first = s + m; 
    second = s + n - 1 - m;

    while (first >= s)
    if (s[first--] != s[second++]) 
        return false; // not equal, so it's not apalindrome  
    return true; // check over, it's a palindrome  
}
/*
1、判断一条单向链表是不是“回文”

分析：对于单链表结构，可以用两个指针从两端或者
中间遍历并判断对应字符是否相等。但这里的关键就是如何朝两个方向遍历。
由于单链表是单向的，所以要向两个方向遍历的话，可以采取经典的快慢指针
的方法，即先位到链表的中间位置，再将链表的后半逆置，
最后用两个指针同时从链表头部和w尾部开始同时遍历并比较即可。

2、判断一个栈是不是“回文”

分析：对于栈的话，只需要将字符串全部压入栈，然后依次将各字符出栈，
这样得到的就是原字符串的逆置串，分别和原字符串各个字符比较，就可以判断了。
*/