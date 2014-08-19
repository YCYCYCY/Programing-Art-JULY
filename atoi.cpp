/*
1 空指针
2 正负号
3 含有不是数字的字符
4 整形溢出：
第一种方法用long long去计数
第二种方法考虑到临界值，当n == MAX_INT / 10 && c = MAX_INT % 10时溢出
*/
int strToInt(const char *str)
{
	static const int MAX_INT =(int)((unsigned)~0>>1);
	static const int MIN_INT = -(int)((unsigned)~0 >> 1) - 1;
	unsigned int n = 0;
	//判断是否输入为空
    if (str == 0)
    {
        return 0;
    }
	//处理空格
    while (isspace(*str))
        ++str;
	//处理正负
    int sign = 1;
    if (*str == '+' || *str == '-')
    {
        if (*str == '-')
            sign = -1;
        ++str;
    }
	//确定是数字后才执行循环
    while (isdigit(*str))
    {
        //处理溢出
        int c = *str - '0';
        if (sign > 0 && (n > MAX_INT / 10 || (n == MAX_INT / 10 && c > MAX_INT % 10)))
        {
            n = MAX_INT;
            break;
        }
        else if (sign < 0 && (n >(unsigned)MIN_INT / 10 || (n == (unsigned)MIN_INT / 10 && c > (unsigned)MIN_INT % 10)))
        {
            n = MIN_INT;
            break;
        }

        //把之前得到的数字乘以10，再加上当前字符表示的数字。
        n = n * 10 + c;
        ++str;
    }
    return sign > 0 ? n : -n;
}