//������Ӵ�
/*
��ö�ٳ�����λ�ã�Ȼ���ڸ�λ��������չ����
*/

int LongestPalindrome(const char *s,int n)
{
	int mid,length,max=0;
	if (s == 0 || n < 1)
        return 0;
	for(mid=0;mid<n;++mid)
	{
		//��midΪ���ģ�����Ϊ����
		for(length=0;(mid-length>=0)&&(mid+length<n);++length)
			if(s[mid-length]!=s[mid+length])
			break;
		if(length*2-1>max)
			max=length*2-1;
		//��midΪ���ģ�����Ϊż��
		for(length=0;(mid-length>=0)&&(mid+length+1<n);++length)
			if(s[mid-length]!=s[mid+length+1])
			break;
		if(length*2>max)
			max=length*2;
	}
	return max;
}