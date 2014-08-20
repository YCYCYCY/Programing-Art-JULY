//实现全排列
/*
解法一、递归实现
从集合中依次选出每一个元素，作为排列的第一个元素，
然后对剩余的元素进行全排列，如此递归处理，从而得到所有元素的全排列。
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

//字典排序遍历
/*下一个排列数算法:next_permutation
定义
升序：相邻两个位置ai < ai+1，ai 称作该升序的首位

步骤（二找、一交换、一翻转）
1 找到排列中最后（最右）一个升序的首位位置i，x = ai
2 找到排列中第i位右边最后一个比ai 大的位置j，y = aj
3 交换x，y
4 把第(i+ 1)位到最后的部分翻转
*/
bool next_permutation(char*perm,int num)
{
	int i;
	//①找到排列中最后（最右）一个升序的首位位置i，x = ai
    for (i = num - 2; (i >= 0) && (perm[i] >= perm[i + 1]); --i);
	// 已经找到所有排列
    if (i < 0){
        return false;
    }
	int k;
	//②找到排列中第i位右边最后一个比ai 大的位置j，y = aj
    for (k = num - 1; (k > i) && (perm[k] <= perm[i]); --k);
	//③交换x，y
    swap(perm[i], perm[k]);
	//④把第(i+ 1)位到最后的部分翻转
    reverse(perm + i + 1, perm + num);
    return true;
}

/*
已知字符串里的字符是互不相同的，现在任意组合，
比如ab，则输出aa，ab，ba，bb，编程按照字典序输出所有的组合。
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
写一个程序，打印出以下的序列。

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