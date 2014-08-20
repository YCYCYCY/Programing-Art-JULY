//�������м�ɨ��
bool IsPalindrome(const char *s, int n)
{
    //�Ƿ�����
    if (s == NULL || n < 1) 
        return false;   
    char *front, *back;

    //��ʼ��ͷָ���βָ��
    front = s; 
    back = s + n - 1; 

    while (front < back) 
    {
        if (*front != *back)
            return false; // ���ǻ��ģ���������  
        ++front;
        --back;
    }
    return true; // �ǻ���  
}


//�м�������ɨ��
bool IsPalindrome2(const char *s, int n)
{
    if (s == NULL || n < 1) 
        return false; // �Ƿ�����  
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
1���ж�һ�����������ǲ��ǡ����ġ�

���������ڵ�����ṹ������������ָ������˻���
�м�������ж϶�Ӧ�ַ��Ƿ���ȡ�������Ĺؼ�������γ��������������
���ڵ������ǵ���ģ�����Ҫ��������������Ļ������Բ�ȡ����Ŀ���ָ��
�ķ���������λ��������м�λ�ã��ٽ�����ĺ�����ã�
���������ָ��ͬʱ������ͷ����wβ����ʼͬʱ�������Ƚϼ��ɡ�

2���ж�һ��ջ�ǲ��ǡ����ġ�

����������ջ�Ļ���ֻ��Ҫ���ַ���ȫ��ѹ��ջ��Ȼ�����ν����ַ���ջ��
�����õ��ľ���ԭ�ַ��������ô����ֱ��ԭ�ַ��������ַ��Ƚϣ��Ϳ����ж��ˡ�
*/