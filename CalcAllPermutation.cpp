//ʵ��ȫ����
/*
�ⷨһ���ݹ�ʵ��
�Ӽ���������ѡ��ÿһ��Ԫ�أ���Ϊ���еĵ�һ��Ԫ�أ�
Ȼ���ʣ���Ԫ�ؽ���ȫ���У���˵ݹ鴦���Ӷ��õ�����Ԫ�ص�ȫ���С�
*/
void CalcAllPermutation(char *perm,int from,int to)
{
	if(to<=1)
	{
		return ;
	}
	if(from==to)
	{
		for(int i=0;i<=to;++i)
			cout<<perm[i];
		cout<<endl;
	}
	else
	{
		for(int j=from;j<=to;j++)
		{
			swap(perm[j], perm[from]);
            CalcAllPermutation(perm, from + 1, to);
            swap(perm[j], perm[from]);
		}
	}
}

//�ֵ��������
/*��һ���������㷨:next_permutation
����
������������λ��ai < ai+1��ai �������������λ

���裨���ҡ�һ������һ��ת��
1 �ҵ�������������ң�һ���������λλ��i��x = ai
2 �ҵ������е�iλ�ұ����һ����ai ���λ��j��y = aj
3 ����x��y
4 �ѵ�(i+ 1)λ�����Ĳ��ַ�ת
*/
bool next_permutation(char*perm,int num)
{
	int i;
	//���ҵ�������������ң�һ���������λλ��i��x = ai
    for (i = num - 2; (i >= 0) && (perm[i] >= perm[i + 1]); --i);
	// �Ѿ��ҵ���������
    if (i < 0){
        return false;
    }
	int k;
	//���ҵ������е�iλ�ұ����һ����ai ���λ��j��y = aj
    for (k = num - 1; (k > i) && (perm[k] <= perm[i]); --k);
	//�۽���x��y
    swap(perm[i], perm[k]);
	//�ܰѵ�(i+ 1)λ�����Ĳ��ַ�ת
    reverse(perm + i + 1, perm + num);
    return true;
}

/*
��֪�ַ�������ַ��ǻ�����ͬ�ģ�����������ϣ�
����ab�������aa��ab��ba��bb����̰����ֵ���������е���ϡ�
*/
void perm(char *result,char *str,int size,int resPos)
{
	if(resPos==size)
		cout<<result;
	else
	{
		for(int i=0;i<size;++i)
		{
			result[resPos]=str[i];
			perm(result,str,size,resPos+1);
		}
	}
}

/*
дһ�����򣬴�ӡ�����µ����С�

(a),(b),(c),(d),(e)........(z)

(a,b),(a,c),(a,d),(a,e)......(a,z),(b,c),(b,d).....(b,z),(c,d).....(y,z)

(a,b,c),(a,b,d)....(a,b,z),(a,c,d)....(x,y,z)

....

(a,b,c,d,.....x,y,z)
*/
char alphabet[]={'a','b','c','d','e','f','g','h',...'z'}
void perm(char *str,int resPos,char Lch,int size)
{
	if(resPos==size)
		cout<<str;
	else{
		for(char ch=Lch+1;ch<='z'-size+resPos+1;++ch)
		{
			str[resPos]=ch;
			perm(str,resPos+1,ch,size)
		}
	}
}
int main()
{
	int length;
	for(length=1;length<=26;++length)
	{
		char str[26];
		resPos=0;
		ch='a';
		per(str,respos,ch-1,length);
		cout<<endl;
	}
}