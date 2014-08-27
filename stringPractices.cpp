/*
1����һ��ֻ����һ�ε��ַ�
��һ���ַ������ҵ���һ��ֻ����һ�ε��ַ���������abaccdeff�������b��
*/
//����һ��˳������,O(n^2)��ʱ�临�Ӷ�
void findFirst(const char *str,int length)
{
	if(str==NULL || length<1)
		return ;
	for(int i =0;i<length;i++)
	{
		char ch1=str[i];
		int j;
		for( j=0;j<length;++j)
		{
			if(i!=j && str[i]==str[j])
				break;
		}
		if(j==length)
		{
			cout<<str[i];
			break;
		}
	}
}
//��������ɨ�����飬��һ�齨��һ��hash��ͳ�Ƹ����ַ����ִ�����
//�ڶ����ҳ���һ�����ִ���Ϊ1���ַ���O(n)��ʱ�临�Ӷ�
void findFirst(const char *str,int length)
{
	if(str==NULL || length<1)
		return ;
	int hashtable[256];
	for(int i=0;i<256;++i)	//��ʼ��
	{
		hashtable[i]=0;
	}
	for(int i=0;i<length;++i)
	{
		hashtable[str[i]]++;
	}
	for(int i=0;i<length;++i)
	{
		if(hashtable[str[i]]==1)
		{
			cout<<str[i];
			break;
		}
	}
}
/*
2���Գ����ַ�������󳤶�

����һ���ַ�����������ַ����жԳƵ����ַ�������󳤶ȡ�
���������ַ�����google�������ڸ��ַ�������ĶԳ����ַ����ǡ�goog����
������4��

��ʾ�����ܺܶ��˶�д���ж�һ���ַ����ǲ��ǶԳƵĺ�����
�����Ŀ���Կ����Ǹú����ļ�ǿ�档
*/
int longestSubString(const char *str,int size)
{
	if(str==NULL ||size<1)
		return 0;
	int max=0;
	for(int i=0;i<size;++i)
	{
		int length=1;
		while(i-length>=0 && i+length<size && str[i-length]==str[i+length])
			length++;
		if(2*length-1>max)
			max=2*length-1;
		int length=1;
		while(i-length>=0 && i+length<size && str[i-length+1]==str[i+length])
			++length;
		if(2*length-2>max)
			max=2*length-2;

	}
	return max;
}

/*
3������ж����������Ƿ��ཻ
http://blog.163.com/song_0803/blog/static/4609759720120910373784/
http://blog.csdn.net/liuxialong/article/details/6556096
�����������������ͷָ�룬����h1��h2���ж������������Ƿ��ཻ��
Ϊ�˼����⣬���Ǽ��������������������

������չ��

�����������л���?
�����Ҫ������������ཻ�ĵ�һ���ڵ���?
*/
//����������������ʱ
//������������ཻ���������һ�����һ���ǹ��еġ�
//�����ཻ�ĵ�һ����㣬��������������ĳ��ȣ�
//Ȼ���ó��ļ�ȥ�̵ĵõ�һ����ֵ K��Ȼ���ó��������ȱ���K����㣬
//Ȼ�����������ٿ�ʼ�Ƚϡ�


//���һ������
LinkNode* IntersectPoint(LinkList list1,LinkList list2,int d)
{
	ListNode *node1=list1,*node2=list2;
	for(int i=0;i<d;++i)
	{
		node1=node1->next;
	}
	while(node1->data!=node2->data)
	{
		node1=node1->next;
		node2=node2->next;
	}
	return node1;
}
//������ʱ
LinkNode* FirstIntersectPoint_NOTLOOP(LinkList list1,LinkList list2)
{
	if(list1==NULL || list2==NULL)
		return -1;
	int length1=0;
	int length2=0;
	LinkNode *node1=list1;
	LinkNode *node2=list2;
	while(node1->next)
	{
		++length1;
		node1=node1->next;
	}
	while(node2->next)
	{
		++lenth2;
		node2=node2->next;
	}

	if(node1!=node2)
		return -1;
	else
	{
		int d;
		if(length1>length2)
		{
			d=length1-length2;
			return IntersectPoint(list1,list2, d);
		}
		else
		{
			d=length2-length1;
			return IntersectPoint(list2,list1, d);
		}
		
	}
}



//���ܴ���
/*
����һ��������ֻ����ͷָ��h��

1������ж��Ƿ���ڻ���

2�����֪�����ĳ��ȣ�

3������ҳ��������ӵ������

4����������ĳ����Ƕ��٣�

5�������������Ƿ��ཻ�������ǵĵ�һ�����㣿

�ⷨ��

1����������1��ʹ��׷�ϵķ������趨����ָ��slow��fast����ͷָ�뿪ʼ��
ÿ�ηֱ�ǰ��1����2��������ڻ����������������粻���ڻ���
fast����NULL�˳���

2����������2����¼������1����ײ��p��slow��fast�Ӹõ㿪ʼ��
�ٴ���ײ���߹��Ĳ��������ǻ��ĳ���s��

3������3���ж�����ײ��p�����ӵ�ľ���=ͷָ�뵽���ӵ�ľ��룬
��ˣ��ֱ����ײ�㡢ͷָ�뿪ʼ�ߣ��������Ǹ���������ӵ㡣

�ö����֤���ɲο���http://fayaa.com/tiku/view/7/

4������3���Ѿ�������ӵ����ͷָ��ĳ��ȣ���������2������Ļ��ĳ��ȣ�
����֮�;��Ǵ���������ĳ���

5�����������ײ�㶼�ڻ��У������������ཻ��һ�����������ײ��һ����
��һ��������Ļ��С�
�������������ཻ���������ǵ��뻷��һ�£����ȼ��������������ĳ��ȣ�
Ȼ���ó��ļ�ȥ�̵ĵõ�һ����ֵ K��Ȼ���ó��������ȱ���K����㣬
Ȼ�����������ٿ�ʼ�Ƚϡ�
�������������ཻ���������ǵ��뻷�㲻һ�¡���û�е�һ�����㡣
*/
//question1:�ж��Ƿ����,����������㡣
LinkNode* IsExitsLoop(LinkList list)
{
	if(list==NULL)
		return NULL;
	LinkNode *fast=list;*slow=list;
	while(fast->next && fast->next->next)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(fast==slow)	//����
		{
			return slow;
			break;
		}
	}
	if(fast->next==NULL || fast->next->next==NULL)
	{
		return NULL;
	}
}
//question2�������л��ĳ���
int LengthOfLoop(LinkList list)
{
	if(list==NULL)
		return 0;
	LinkNode *meetNode=IsExitsLoop(list);
	if(meetNode==NULL)
		return 0;
	LinkNode *slow=meetNode,fast=meetNode;
	int length=1;
	while(slow!=fast)
	{
		slow=slow->next;
		fast=fast->next->next;
		length++;
	}
	return length;
}
//question3�������л�����ڵ�
LinkNode *FindLoopPoint(LinkList list)
{
	if(list==NULL)
		return NULL;
	LinkNode *meetNode=IsExitsLoop(list);
	if(meetNode==NULL)
		return NULL;
	LinkNode *node1=meetNode,*node2=list;
	while(node1!=node2)
	{
		node1=node1->next;
		node2=node2->next;
	}
	return node1;
}
//question4:����ĳ���
int LengthOfList(LinkList list)
{
	if(list==NULL)
		return 0;
	int length;
	LinkNode *meetNode=IsExitsLoop(list);
	if(meetNode==NULL)	//�����ڻ�
	{
		length=0;
		LinkNode *node=list;
		while(node->next)
		{
			node=node->next;
			++length;
		}
		return length;
	}
	else
	{
		int loopLength=LengthOfLoop(list);
		LinkNode *entranceNode=FindLoopPoint(list);
		LinkNode *node=list;
		int prefixLength=0;
		while(node->next!=list)
		{
			node=node->next;
			++prefixLength;
		}
		return loopLength+prefixLength;
	}
}
LinkNode * FirstIntersectPoint_LOOP(LinkList list1,LinkList list2,LinkNode *meetNode1,LinkNode *meetNode2)
{
	bool IsIntersect=false;
	LinkNode *node=meetNode2;
	do
	{
		if(node!=meetNode1)
			node=node->next;
		else
		{
			IsIntersect=true;
			break;
		}
	}while (node!=meetNode2);
		
	if(IsIntersect)	//�ཻ
	{
		LinkNode *node1,*node2;	//������list1��list2���뻷�㡣
		node1=FindLoopPoint(list1);
		node2=FindLoopPoint(list2);
		if(node1==node2)	//������list1��list2���뻷����ͬʱ
		{
			int length1=LengthOfList(LinkList list1);
			int length2=LengthOfList(LinkList list2);
			int d;
			if(length1>length2)
			{
				d=length1-length2;
				return IntersectPoint(list1,list2, d);
			}
			else
			{
				d=length2-length1;
				return IntersectPoint(list2,list1, d);
			}
		}
		else
		{
			cout<<"�ཻ�ڻ��ڣ�û�е�һ������"<<endl;
			return node1;
		}
		
	}
	else	//���ཻ��û�н���
	{
		return NULL;
	}
}
//��������ĵ�һ������
LinkNode *FirstIntersectPoint(LinkList list1,LinkList list2)
{
	if(list1==NULL || list2==NULL)
	{
		return NULL;
	}
	LinkNode *meetNode1=IsExitsLoop(list1);
	LinkNode *meetNode2=IsExitsLoop(list2);
	if(meetNode1==NULL ^ meetNode2==NULL)	//һ���л�,һ��û��
		return NULL;
	else if(meetNode1==NULL && meetNode2==NULL)	//��û�л�
	{
		return FirstIntersectPoint_NOTLOOP(list1,list2);
	}
	else	//���л�
	{
		return FirstIntersectPoint_LOOP(list1,list2,meetNode1,meetNode2)
	}
}




/*
4�������������

����һ�������ͷ��㣬��β��ͷ���������ÿ������ֵ��
*/

/*
5����O(1)ʱ����ɾ����������

�����������һ������ָ�룬ͬʱ�ý�㲻��β��㣬
����û��ָ�������κν���ָ�룬����O(1)ʱ����ɾ���ý�㡣
*/
void deleteNode(LinkNode *pNode)
{
	LinkNode *node=pNode->next;
	pNode->data=node->data;
	pnode->next=node->next;
	delete(node);
}

/*
6���ҳ�����ĵ�һ���������

�������������ҳ����ǵĵ�һ��������㡣
*/
LinkNode*IntersectPoint(LinkNode *head1,LinkNode *head2,int d)
{
	for(int i=0;i<d;++i)
	{
		head1=head1->next;
	}
	while(head1->data!=head2->data)
	{
		head1=head1->next;
		head2=head2->next;
	}
	return head1;
}
LinkNode* findFirstIntersectPoint(LinkNode *head1,LinkList *head2)
{
	if(head1==NULL ||head2==NULL)
		return NULL;
	int length1=0,length2=0;
	while(head1->next)
	{
		++length1;
		head1=head1->next;
	}
	while(head2->next)
	{
		++length2;
		head2=head2->next;
	}
	int d;
	if(head1!=head2)
		return NULL;
	if(length1>length2)
	{
		d=length1-length2;
		return IntersectPoint(head1,head2,d);
	}
	else
	{
		d=length2-length1;
		return IntersectPoint(head2,head1,d);
	}
}

/*
7�����ַ�����ɾ���ض����ַ�

���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ���

���磬���롱They are students.���͡�aeiou����
��ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.����
*/
//һ������һ��hashtable,��¼�ڶ����ַ����г��ֵ��ַ���
//�����������ַ���pfast��pslow�ֱ�ָ���һ���ַ��б�������λ�ú�Ҫ�����λ��
char* stringDelChara(char *src,char *dest)
{
	//*str=��They are students.�� *dest=��aeiou��
	int hashTabel[256]={0};
	char *p=dest;
	while(*p!='\0')
	{
		hashTable[(int)*p]=1;
		++p;
	}
	char *pfast=src,*pslow=src;
	while(*pfast!='\0')
	{
		if(hashTable[(int)*pfast]==0)
		{
			*pslow=*pfast;
			pslow++;
		}
		++pfast;
	}
	src[index]='\0';
	return src;
}

/*
8���ַ�����ƥ��

��һƪӢ�������в���ָ��������������ʹ�ö�ʮ����Ӣ����ĸ
�������Ǵ�д��Сд�����ո��Լ�����ͨ�����ɣ���?����
ͨ���������ʾ�������������ĸ��ͨ�����?����ʾһ��������ĸ��
�磺��J* Smi??�� ����ƥ�䡰John Smith�� .
*/
const char *pEnd=NULL;
bool match(const char *pszText,const char *pszName)  
{  
    if(*pszName == '/0')    // ƥ�����  
    {  
        pEnd=pszText;  
        return true;  
    }  
   
    if(*pszText == '/0')    //    δƥ�����  
    {  
        if(*pszName == '*')  
        {  
            pEnd=pszText;  
            return true;  
        }  
    
        return false;  
    }  
   
    if(*pszName!= '*' && *pszName!='?')  
    {  
        if(*pszText == *pszName)  
        {  
            return match(pszText+1,pszName+1);  
        }  
    
        return false;  
    }  
    else  
    {  
        if(*pszName == '*')  
        {  
            return match(pszText,pszName+1)||match(pszText+1,pszName);   
             //ƥ��0��,���߼���*ƥ����ȥ  
        }  
        else  
        {  
            return match(pszText+1,pszName+1);  
        }  
    }  
}
void scan(const char *pszText, const char *pszName)  
{  
    while(*pszText!='/0')  
    {  
        if(match(pszText,pszName))  
        {  
            while(pszText!=pEnd)  
            {  
                cout<<*pszText++;  
            }  
     
            cout<<endl;  
        }    
        return;  
    }  
}  

/*
9���ַ�������ͳ��

char *str = "AbcABca"; д��һ��������
���ҳ�ÿ���ַ��ĸ��������ִ�Сд��Ҫ��ʱ�临�Ӷ���n����ʾ��ASCII�룩
*/
//��hash��ͳ��


/*
10����С�Ӵ�

��һƪ���£���������һ����������ɣ������м�ո������
�ٸ�һ���ַ���ָ�����飬���� char *str[]={"hello","world","good"};
�������а�������ַ���ָ���������С�Ӵ���
ע�⣬ֻҪ�������ɣ�û��˳��Ҫ��
*/
/*
˼·1����һ�����飬��¼�ַ������и����ַ���������ֵ��±꣬
ÿ���ҵ�һ�����ַ������г��ֵ��ַ��������������±ꡣ
Ȼ��������º����̾��롣��֮ǰ��¼��MINֵ�Ƚϡ�
�����MINֵ�������Ѱ����һ���ַ������ֵ�λ�á�
�����MINֵС�������MINֵ����������ַ�������ʼλ�ü�¼��start��

˼·2��ɨ�����ʼ�ձ���һ��[left,right]��range,
��ʼ��ȷ��[left,right]��range��������йؼ�����ֹͣ��Ȼ��ÿ�ε�����
	1 ��ͼ���ƶ�left��ֹͣ����Ϊ���ƶ��������޷��������йؼ��֡�
	2 �Ƚϵ�ǰrange's length��best length����������ֵ��
	3 ����right��ֹͣ����Ϊʹ����һ���ؼ��ֵļ���+1��
	4 �ظ�������
*/

/*
11���ַ����ļ���

����һ���ַ����ļ��ϣ���ʽ�磺{aaa bbb ccc}�� {bbb ddd}��
{eee fff}��{ggg}��{ddd hhh}Ҫ�����н�����Ϊ�յļ��Ϻϲ���
Ҫ��ϲ���ɺ�ļ���֮���޽�������������Ӧ���
{aaa bbb ccc ddd hhh}��{eee fff}�� {ggg}��

��ʾ�����鼯��
*/

/*
12����ʱ���

��ʵı��뷶Χ��a ~ y��25����ĸ����1λ��4λ�ı��룬������ǰ���ʵ�
���밴�ֵ��������γ�һ���������£�a, aa, aaa, aaaa, aaab, 
aaac, �� ��, b, ba, baa, baaa, baab, baac �� ��, yyyw, yyyx, yyyy 
����a��IndexΪ0��aa��IndexΪ1��aaa��IndexΪ2���Դ����ơ�

��дһ������������������һ�����룬����baca�������������Ӧ��Index��
��дһ������������������һ��Index������12345��������Index��Ӧ�ı��롣
*/
//http://blog.csdn.net/jiangnanyouzi/article/details/6827534
//http://www.cnblogs.com/daniagger/archive/2012/07/20/2600581.html
int encode(const char *str)  
{  
    int len = 0;  
    int index = 0;  
    int factor[] = {1+25+25*25+25*25*25, 1+25+25*25, 1+25, 1};    
    while(*str)  
        index += factor[len++] * (*str++ - 'a');  
    return index + (len - 1);  
}  

// dstΪ����5�ַ����ַ�����  
void decode(char *dst, int index)  
{  
    int i = 0;   
    int factor[] = {1+25+25*25+25*25*25, 1+25+25*25, 1+25, 1};  
    while(index >= 0)   
    {  
        *dst++ = 'a' + index / factor[i];  
         index %= factor[i++];   
        --index; // �˴�Ҫ��1����ԭ����һ���ַ�   
    }  
    *dst = '\0';  
}  
/*
13����ظ��Ӵ�

һ������Ϊ10000���ַ�����дһ���㷨���ҳ�����ظ��Ӵ���
��abczzacbca,�����bc��

��ʾ�������Ǻ�׺��/����ĵ���Ӧ�ã��������׺�����height[]�����ֵ��
ͬ15��
*/


/*
14���ַ�����ѹ��

һ���ַ�����ѹ�����е������ո�Ϊ1���󣬶����е�ÿ���ִ������ӡ������
����"abc efg hij"��ӡΪ"cba gfe jih"��
ͬ7��
*/



/*
15������ظ������Ӵ�

����һ���ַ��������������ظ����ֵ��ַ����أ�
��������ttabcftrgabcd,������Ϊabc, canffcancd,������Ϊcan��

����һ���ַ��������������ظ��Ӵ���

������ʹ�ú�׺���飬��һ���ַ���������Ӧ�ĺ�׺�����
Ȼ�����������������μ�����ڵ������ַ����Ŀ�ͷ�������֡� 
������ʱ�临�Ӷ�Ϊ��

���ɺ�׺���� O(N)
���� O(NlogN*N) ������ N ����Ϊ�ַ����Ƚ�Ҳ�� O(N)
���μ�����ڵ������ַ��� O(N * N)
�������ܵ�ʱ�临�Ӷ��� O(N^2*logN)
*/

/*
16���ַ�����ɾ��

ɾ��ģʽ���г��ֵ��ַ����硰welcome to asted��,ģʽ��Ϊ��aeiou����
��ô�õ����ַ���Ϊ��wlcm t std"��Ҫ���������š�
ͬ��7��
*/

/*
17���ַ������ƶ�

�ַ���Ϊ*�ź�26����ĸ��������ϣ��� *�Ŷ��ƶ�������࣬
����ĸ�Ƶ����Ҳಢ�������˳�򲻱䣬Ҫ��ʱ��Ϳռ临�Ӷ���С��
�Ӻ���ǰ������������ָ�룬һ��ָ��ָ��ǰ�����λ�ã�
��һ��ָ��ָ��ǰ��������λ��

*/

char* moveStar(char *s){  
    if(!s) return NULL;  
    int len = strlen(s);  
    char *pfast=s[len-1];
	char *pnow =s[len-1];
	while(pfast>=s)
	{
		if(*pfast!='*')
		{
			*pnow=*pfast;
			--pnow;
		}
		--pfast;

	}
	char *p=s;
	while(p<=pnow)
	{
		*p='*';
	}
	
    return s;  
}  

/*
18���ַ����İ���

���룺

L:��hello����july��

S:��hellomehellojuly��

�����july

�����S�а�����Lһ�����ʣ�Ҫ���������ֻ����һ�Σ�
����ж������һ�εģ������һ�������ĵ��ʡ�

ͬ��1��
һ�����L�и�������S�г��ֵĴ���
��������L�ҵ���һ��ֻ����һ�εĵ���
*/

/*19��������n��Ԫ��

��������n��Ԫ�ء�

��ʾ������һǰһ������ָ�룬һ��ָ������n��������ָ��һ���ߡ�
��ǰ���ָ���ߵ�����β��ʱ����һָ��ָ���Ԫ�ؼ�Ϊ��������n��Ԫ�ء�
*/

/*
20�������ַ���

��һ���ܳ����ַ������ָ��һ��һ�ε����ַ��������ַ������ǻ����ַ�����
�л����ַ����������ģ�û�л��ľ����һ��һ�����ַ���

���磺

habbafgh

���h,abba,f,g,h��

��ʾ��һ����˻��뵽�ú�׺���������������⡣
*/

/*
21��������ַ�

�õݹ��㷨дһ�����������ַ���������ַ��ĳ��ȣ�
����aaaabbcc�ĳ���Ϊ4��aabb�ĳ���Ϊ2��ab�ĳ���Ϊ1��

˼·:��һ��int������max��¼��󳤶ȣ�������ָ��pfast��pslow��������
�ַ���������������ȡ������maxֵ�󣬸��¡�
*/

/*
22���ַ�����ת

ʵ���ַ�����ת������

˼·������ָ��ֱ�ָ��ͷβ������ֵ����ָ�������ƶ�
*/

/*
22���ַ���ѹ��

ͨ����������һ��Сд��ĸ(a~z)��ɵ��ַ��������дһ���ַ���ѹ������
���ַ�����������ϯ���ظ���ĸ����ѹ���������ѹ������ַ����� ѹ������

	��ѹ�������ظ����ֵ��ַ��������ַ���"abcbc"�����������ظ��ַ���
	ѹ������ַ�������"abcbc"��

	ѹ���ֶεĸ�ʽΪ"�ַ��ظ��Ĵ���+�ַ�"��
	���磺�ַ���"xxxyyyyyyz"ѹ����ͳ�Ϊ"3x6yz"��
Ҫ��ʵ�ֺ�����
void stringZip(const char *pInputStr, long lInputLen, char *pOutputStr);

����pInputStr�� �����ַ���	lInputLen�� �����ַ�������
��� pOutputStr�� ����ַ������ռ��Ѿ����ٺã��������ַ����ȳ���

ע�⣺ֻ��Ҫ��ɸú��������㷨���м䲻��Ҫ���κ�IO���������

ʾ��

���룺��cccddecc�� �������3c2de2c��
���룺��adef�� �������adef��
���룺��pppppppp�� �������8p��

Ҫ���ǰ�����ת����char�ͣ���Ҫ������λ������λ���ȵȵ������
˼·��������ָ��pfast��pslow���������ַ������ҳ���ͬ�ַ��ĸ�����
����һ���ַ������飬������ķ���������ת��Ϊ�ַ�����
������С���ǵ�λ������Ǹ�λ��
��һ��ָ��pointָ������ַ��������λ��
*/
int IntToString(int num,char *str)
{
	int i=0;
	int j=0;
	int count=0;
	while(num!=0)
	{
		count++;
		i=num%10;
		str[j++]=i+'0';
		num=num/10;
	}
	return count;
}
void stringZip(const char *pInputStr, long lInputLen, char *pOutputStr)
{
	int fast=0;
	int slow=0;
	int point=0;
	int count;
	char num[10]={0};
	while(fast<lInputLen)
	{
		if(pInputStr[fast]==pInputStr[fast+1])
			++fast;
		else
		{
			count=fast-slow+1;
			if(count!=1)
			{
				int numcount=IntToString(count,num);
				char *p=num;
				while(p!='0')
				{
					pOutputStr[point+numcount-1]=*p;
					++p;
					--numcount;
				}
				pOutputStr[point+numcount]=pInputStr[fast];
				point=point+numcount+1;
			}
			else
			{
				pOutputStr[point]=pInputStr[fast];
				point++;
			}
			fast++;
			slow=fast;
		}
			
	}
}

/*
23�����ϵĲ

��֪����A��B��Ԫ�طֱ��ò���ͷ���ĵ�����洢�����󼯺�A��B�Ĳ��
������������ڼ���A�ĵ������С����磬������A={5,10,20,15,25,30}��
����B={5,15,35,25}����ɼ����A={10,20,30}��

˼·���Ѽ���B�е�ֵȡ�����洢һ������C��Ȼ���ÿ�����������˳��
Ȼ�����A��ÿһ��Ԫ�أ�������C�����в��ҡ�����ҵ��ˣ�����A��ɾȥ��Ԫ�ء�
*/


/*
24��������Ӵ�

�����ַ���A��B�����A��B�еĵ�һ��������Ӵ���
����A=��wepiabc B=��pabcni�����������abc����

˼·���ֱ�����A��B�ĺ�׺���飬�ٰ������ֵ�����Ȼ���ó��ȶ̵��ַ�����
��׺����ȥƥ�䳤�ַ�����׺���顣
*/


/*
25������01

����һ���ַ��������Ȳ�����100������ֻ�����ַ�0��1,
�����ַ�0��1���ֵô�������ż��������԰��ַ��������з֣�
���зֺ���ַ�������ָ������ˣ��������˵õ���0���ܸ�����ȣ�
�õ���1���ܸ���Ҳ��ȡ�

���磬���봮��010111,���ǿ��԰Ѵ���λ01, 011,��1��
�ѵ�1�κ͵�3�η���һ��ָ�һ���ˣ��ڶ��ηָ�����һ���ˣ�
����ÿ���˶��õ���1��0������1������Ҫ���������зֵĴ����������١�

���ǵ������������ǰ��ַ����з�(n - 1)���γ�n������Ϊ1�Ĵ���

˼·�������з�һ�Ρ�
	  ����ʲô����һ�������з�������ɡ�
֤����

���������������β�����������ӵ���A�������е���B��
	��ֱ��AB��L��L�����ҵ�0�ĸ�������ȣ���������ߴ����ұߡ�
	˳ʱ����תֱ��L��ÿ��תһ����������0�ĸ���ֻ���ܷ������ֱ仯��
	���䣬+1��-1 ��

��������תһ�ܵ�ʱ��ֱ�߻ص�ԭ����λ�ã���ʱ���С���ұߡ�
	����0�ĸ����ı仯�������ģ�����һ����һ��ʱ�̣���ߵ���һ�롣

*/
#include <stdio.h>
#include <string.h>

int howmany(char *s)
{
    int i, len = strlen(s);
    int t = 0;
	int num=0;
	int num1=0;
	for(i=0;i<len;++i)
	{
		if(s[i]=='0')
		{
			++num;
			if(i<len/2)
				++num1;
		}

	}
	for (i = 0; i < len/2; ++i)
    {
        if (s[i] == '0')
        {
            --num1;
        }
        if (s[i+len] == '0')
        {
            ++num1;
        }
		if(num!==len/2)
			break;
    }
    return i;
}

/*
26���Ϸ��ַ���

��n����ͬ���ַ������1 - n�������һ���ַ�����������2��Ҫ��

1�����ڱ��Ϊi ���ַ������2 * i > n������ַ�������Ϊ���һ���ַ���
��������ַ�������Ϊ���һ���ַ��Ļ�������ַ�������Խ������ַ���
2�����ڱ��Ϊi���ַ������2 * i <= n������ַ���������Ϊ���һ���ַ���
�Ҹ��ַ������������ŵ���һ���ַ��ı��һ��Ҫ >= 2 * i��

���ж��ٳ���ΪM�ҷ����������ַ�����

���磺N = 2��M = 3����abb, bab, bbb�Ƿ����������ַ�����
ʣ�µľ�Ϊ�������������ַ�����

�ٶ�n��m�����㣺2<=n,m<=1000000000)��

˼·��http://blog.csdn.net/kevinkitty_love/article/details/17735903
*/

/*
27�����ժҪ����
ͬ10��
*/

/*
28��ʵ��memcpy����
29��ʵ��memmove����
��ʾ��memmove����Ҫ���Ƿ����ص��������
*/