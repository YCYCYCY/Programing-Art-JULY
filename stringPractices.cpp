/*
1、第一个只出现一次的字符
在一个字符串中找到第一个只出现一次的字符。如输入abaccdeff，则输出b。
*/
//方法一：顺序搜索,O(n^2)的时间复杂度
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
//方法二：扫描两遍，第一遍建立一个hash表统计各个字符出现次数，
//第二遍找出第一个出现次数为1的字符。O(n)的时间复杂度
void findFirst(const char *str,int length)
{
	if(str==NULL || length<1)
		return ;
	int hashtable[256];
	for(int i=0;i<256;++i)	//初始化
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
2、对称子字符串的最大长度

输入一个字符串，输出该字符串中对称的子字符串的最大长度。
比如输入字符串“google”，由于该字符串里最长的对称子字符串是“goog”，
因此输出4。

提示：可能很多人都写过判断一个字符串是不是对称的函数，
这个题目可以看成是该函数的加强版。
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
3、编程判断俩个链表是否相交
http://blog.163.com/song_0803/blog/static/4609759720120910373784/
http://blog.csdn.net/liuxialong/article/details/6556096
给出俩个单向链表的头指针，比如h1，h2，判断这俩个链表是否相交。
为了简化问题，我们假设俩个链表均不带环。

问题扩展：

如果链表可能有环列?
如果需要求出俩个链表相交的第一个节点列?
*/
//当两个链表都不带环时
//如果两个链表相交，他们最后一个结点一定是共有的。
//对于相交的第一个结点，则可求出两个链表的长度，
//然后用长的减去短的得到一个差值 K，然后让长的链表先遍历K个结点，
//然后两个链表再开始比较。


//求第一个交点
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
//不带环时
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



//可能带环
/*
给定一个单链表，只给出头指针h：

1、如何判断是否存在环？

2、如何知道环的长度？

3、如何找出环的连接点在哪里？

4、带环链表的长度是多少？

5、两个环链表是否相交？求他们的第一个交点？

解法：

1、对于问题1，使用追赶的方法，设定两个指针slow、fast，从头指针开始，
每次分别前进1步、2步。如存在环，则两者相遇；如不存在环，
fast遇到NULL退出。

2、对于问题2，记录下问题1的碰撞点p，slow、fast从该点开始，
再次碰撞所走过的操作数就是环的长度s。

3、问题3：有定理：碰撞点p到连接点的距离=头指针到连接点的距离，
因此，分别从碰撞点、头指针开始走，相遇的那个点就是连接点。

该定理的证明可参考：http://fayaa.com/tiku/view/7/

4、问题3中已经求出连接点距离头指针的长度，加上问题2中求出的环的长度，
二者之和就是带环单链表的长度

5、环链表的碰撞点都在环中，若两个链表相交，一个环链表的碰撞点一定在
另一个环链表的环中。
若两个环链表相交，并且他们的入环点一致，可先计算出两个环链表的长度，
然后用长的减去短的得到一个差值 K，然后让长的链表先遍历K个结点，
然后两个链表再开始比较。
若两个环链表相交，并且他们的入环点不一致。则没有第一个交点。
*/
//question1:判断是否带环,返回相遇结点。
LinkNode* IsExitsLoop(LinkList list)
{
	if(list==NULL)
		return NULL;
	LinkNode *fast=list;*slow=list;
	while(fast->next && fast->next->next)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(fast==slow)	//相遇
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
//question2：链表中环的长度
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
//question3：链表中环的入口点
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
//question4:链表的长度
int LengthOfList(LinkList list)
{
	if(list==NULL)
		return 0;
	int length;
	LinkNode *meetNode=IsExitsLoop(list);
	if(meetNode==NULL)	//不存在环
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
		
	if(IsIntersect)	//相交
	{
		LinkNode *node1,*node2;	//环链表list1和list2的入环点。
		node1=FindLoopPoint(list1);
		node2=FindLoopPoint(list2);
		if(node1==node2)	//环链表list1和list2的入环点相同时
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
			cout<<"相交在环内，没有第一个交点"<<endl;
			return node1;
		}
		
	}
	else	//不相交，没有交点
	{
		return NULL;
	}
}
//求两链表的第一个交点
LinkNode *FirstIntersectPoint(LinkList list1,LinkList list2)
{
	if(list1==NULL || list2==NULL)
	{
		return NULL;
	}
	LinkNode *meetNode1=IsExitsLoop(list1);
	LinkNode *meetNode2=IsExitsLoop(list2);
	if(meetNode1==NULL ^ meetNode2==NULL)	//一个有环,一个没环
		return NULL;
	else if(meetNode1==NULL && meetNode2==NULL)	//都没有环
	{
		return FirstIntersectPoint_NOTLOOP(list1,list2);
	}
	else	//都有环
	{
		return FirstIntersectPoint_LOOP(list1,list2,meetNode1,meetNode2)
	}
}




/*
4、逆序输出链表

输入一个链表的头结点，从尾到头反过来输出每个结点的值。
*/

/*
5、在O(1)时间内删除单链表结点

给定单链表的一个结点的指针，同时该结点不是尾结点，
此外没有指向其它任何结点的指针，请在O(1)时间内删除该结点。
*/
void deleteNode(LinkNode *pNode)
{
	LinkNode *node=pNode->next;
	pNode->data=node->data;
	pnode->next=node->next;
	delete(node);
}

/*
6、找出链表的第一个公共结点

两个单向链表，找出它们的第一个公共结点。
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
7、在字符串中删除特定的字符

输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。

例如，输入”They are students.”和”aeiou”，
则删除之后的第一个字符串变成”Thy r stdnts.”。
*/
//一、建立一个hashtable,记录第二个字符串中出现的字符。
//二、用两个字符串pfast和pslow分别指向第一个字符中遍历到的位置和要插入的位置
char* stringDelChara(char *src,char *dest)
{
	//*str=”They are students.” *dest=”aeiou”
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
8、字符串的匹配

在一篇英文文章中查找指定的人名，人名使用二十六个英文字母
（可以是大写或小写）、空格以及两个通配符组成（、?），
通配符“”表示零个或多个任意字母，通配符“?”表示一个任意字母。
如：“J* Smi??” 可以匹配“John Smith” .
*/
const char *pEnd=NULL;
bool match(const char *pszText,const char *pszName)  
{  
    if(*pszName == '/0')    // 匹配完成  
    {  
        pEnd=pszText;  
        return true;  
    }  
   
    if(*pszText == '/0')    //    未匹配完成  
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
             //匹配0个,或者继续*匹配下去  
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
9、字符个数的统计

char *str = "AbcABca"; 写出一个函数，
查找出每个字符的个数，区分大小写，要求时间复杂度是n（提示用ASCII码）
*/
//用hash表统计


/*
10、最小子串

给一篇文章，里面是由一个个单词组成，单词中间空格隔开，
再给一个字符串指针数组，比如 char *str[]={"hello","world","good"};
求文章中包含这个字符串指针数组的最小子串。
注意，只要包含即可，没有顺序要求。
*/
/*
思路1：开一个数组，记录字符串集中各个字符串最近出现的下标，
每次找到一个在字符串集中出现的字符串，都更新其下标。
然后求出更新后的最短距离。与之前记录的MIN值比较。
如果比MIN值大，则继续寻找下一个字符串出现的位置。
如果比MIN值小，则更新MIN值，并把这个字符串的起始位置记录到start中

思路2：扫描过程始终保持一个[left,right]的range,
初始化确保[left,right]的range里包含所有关键字则停止。然后每次迭代：
	1 试图右移动left，停止条件为再移动将导致无法包含所有关键字。
	2 比较当前range's length和best length，更新最优值。
	3 右移right，停止条件为使任意一个关键字的计数+1。
	4 重复迭代。
*/

/*
11、字符串的集合

给定一个字符串的集合，格式如：{aaa bbb ccc}， {bbb ddd}，
{eee fff}，{ggg}，{ddd hhh}要求将其中交集不为空的集合合并，
要求合并完成后的集合之间无交集，例如上例应输出
{aaa bbb ccc ddd hhh}，{eee fff}， {ggg}。

提示：并查集。
*/

/*
12、五笔编码

五笔的编码范围是a ~ y的25个字母，从1位到4位的编码，如果我们把五笔的
编码按字典序排序，形成一个数组如下：a, aa, aaa, aaaa, aaab, 
aaac, … …, b, ba, baa, baaa, baab, baac … …, yyyw, yyyx, yyyy 
其中a的Index为0，aa的Index为1，aaa的Index为2，以此类推。

编写一个函数，输入是任意一个编码，比如baca，输出这个编码对应的Index；
编写一个函数，输入是任意一个Index，比如12345，输出这个Index对应的编码。
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

// dst为至少5字符的字符数组  
void decode(char *dst, int index)  
{  
    int i = 0;   
    int factor[] = {1+25+25*25+25*25*25, 1+25+25*25, 1+25, 1};  
    while(index >= 0)   
    {  
        *dst++ = 'a' + index / factor[i];  
         index %= factor[i++];   
        --index; // 此处要减1，还原到下一个字符   
    }  
    *dst = '\0';  
}  
/*
13、最长重复子串

一个长度为10000的字符串，写一个算法，找出最长的重复子串，
如abczzacbca,结果是bc。

提示：此题是后缀树/数组的典型应用，即是求后缀数组的height[]的最大值。
同15题
*/


/*
14、字符串的压缩

一个字符串，压缩其中的连续空格为1个后，对其中的每个字串逆序打印出来。
比如"abc efg hij"打印为"cba gfe jih"。
同7题
*/



/*
15、最大重复出现子串

输入一个字符串，如何求最大重复出现的字符串呢？
比如输入ttabcftrgabcd,输出结果为abc, canffcancd,输出结果为can。

给定一个字符串，求出其最长的重复子串。

分析：使用后缀数组，对一个字符串生成相应的后缀数组后，
然后再排序，排完序依次检测相邻的两个字符串的开头公共部分。 
这样的时间复杂度为：

生成后缀数组 O(N)
排序 O(NlogN*N) 最后面的 N 是因为字符串比较也是 O(N)
依次检测相邻的两个字符串 O(N * N)
故最终总的时间复杂度是 O(N^2*logN)
*/

/*
16、字符串的删除

删除模式串中出现的字符，如“welcome to asted”,模式串为“aeiou”，
那么得到的字符串为“wlcm t std"，要求性能最优。
同第7题
*/

/*
17、字符串的移动

字符串为*号和26个字母的任意组合，把 *号都移动到最左侧，
把字母移到最右侧并保持相对顺序不变，要求时间和空间复杂度最小。
从后往前遍历，设两个指针，一个指针指向当前插入的位置，
另一个指针指向当前遍历到的位置

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
18、字符串的包含

输入：

L:“hello”“july”

S:“hellomehellojuly”

输出：july

输出：S中包含的L一个单词，要求这个单词只出现一次，
如果有多个出现一次的，输出第一个这样的单词。

同第1题
一、求出L中各单词在S中出现的次数
二、遍历L找到第一个只出现一次的单词
*/

/*19、倒数第n个元素

链表倒数第n个元素。

提示：设置一前一后两个指针，一个指针先走n步后，两个指针一起走。
当前面的指针走到链表尾端时，另一指针指向的元素即为链表倒数第n个元素。
*/

/*
20、回文字符串

将一个很长的字符串，分割成一段一段的子字符串，子字符串都是回文字符串。
有回文字符串就输出最长的，没有回文就输出一个一个的字符。

例如：

habbafgh

输出h,abba,f,g,h。

提示：一般的人会想到用后缀数组来解决这个问题。
*/

/*
21、最长连续字符

用递归算法写一个函数，求字符串最长连续字符的长度，
比如aaaabbcc的长度为4，aabb的长度为2，ab的长度为1。

思路:用一个int型数据max记录最大长度，用两个指针pfast和pslow遍历整个
字符串，求出各个长度。如果比max值大，更新。
*/

/*
22、字符串反转

实现字符串反转函数。

思路：两个指针分别指向头尾，交换值后两指针向里移动
*/

/*
22、字符串压缩

通过键盘输入一串小写字母(a~z)组成的字符串。请编写一个字符串压缩程序，
将字符串中连续出席的重复字母进行压缩，并输出压缩后的字符串。 压缩规则：

	仅压缩连续重复出现的字符。比如字符串"abcbc"由于无连续重复字符，
	压缩后的字符串还是"abcbc"。

	压缩字段的格式为"字符重复的次数+字符"。
	例如：字符串"xxxyyyyyyz"压缩后就成为"3x6yz"。
要求实现函数：
void stringZip(const char *pInputStr, long lInputLen, char *pOutputStr);

输入pInputStr： 输入字符串	lInputLen： 输入字符串长度
输出 pOutputStr： 输出字符串，空间已经开辟好，与输入字符串等长；

注意：只需要完成该函数功能算法，中间不需要有任何IO的输入输出

示例

输入：“cccddecc” 输出：“3c2de2c”
输入：“adef” 输出：“adef”
输入：“pppppppp” 输出：“8p”

要考虑把数字转化成char型，还要考虑两位数或三位数等等的情况。
思路：用两个指针pfast和pslow遍历输入字符串，找出相同字符的个数。
申请一个字符串数组，用求余的方法把数字转化为字符串。
数组中小的是低位，大的是高位。
用一个指针point指向输出字符串的输出位置
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
23、集合的差集

已知集合A和B的元素分别用不含头结点的单链表存储，请求集合A与B的差集，
并将结果保存在集合A的单链表中。例如，若集合A={5,10,20,15,25,30}，
集合B={5,15,35,25}，完成计算后A={10,20,30}。

思路：把集合B中的值取出来存储一个数组C，然后用快速排序整理顺序。
然后遍历A中每一个元素，在数组C中折中查找。如果找到了，就在A中删去该元素。
*/


/*
24、最长公共子串

给定字符串A和B，输出A和B中的第一个最长公共子串，
比如A=“wepiabc B=“pabcni”，则输出“abc”。

思路：分别生成A和B的后缀数组，再把它们字典排序。然后用长度短的字符串的
后缀数组去匹配长字符串后缀数组。
*/


/*
25、均分01

给定一个字符串，长度不超过100，其中只包含字符0和1,
并且字符0和1出现得次数都是偶数。你可以把字符串任意切分，
把切分后得字符串任意分给两个人，让两个人得到的0的总个数相等，
得到的1的总个数也相等。

例如，输入串是010111,我们可以把串切位01, 011,和1，
把第1段和第3段放在一起分给一个人，第二段分给另外一个人，
这样每个人都得到了1个0和两个1。我们要做的是让切分的次数尽可能少。

考虑到最差情况，则是把字符串切分(n - 1)次形成n个长度为1的串。

思路：可以切分一次。
	  不管什么串，一定可以切分两次完成。
证明：

　　把这个串的首尾相连，设连接点是A，串的中点是B，
	设直线AB是L，L的左右的0的个数不相等，不妨设左边大于右边。
	顺时针旋转直线L，每旋转一次左右两边0的个数只可能发生两种变化：
	不变，+1，-1 。

　　等旋转一周的时候，直线回到原来的位置，此时左边小于右边。
	由于0的个数的变化是连续的，所以一定有一个时刻，左边等于一半。

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
26、合法字符串

用n个不同的字符（编号1 - n），组成一个字符串，有如下2点要求：

1、对于编号为i 的字符，如果2 * i > n，则该字符可以作为最后一个字符，
但如果该字符不是作为最后一个字符的话，则该字符后面可以接任意字符；
2、对于编号为i的字符，如果2 * i <= n，则该字符不可以作为最后一个字符，
且该字符后面所紧接着的下一个字符的编号一定要 >= 2 * i。

问有多少长度为M且符合条件的字符串。

例如：N = 2，M = 3。则abb, bab, bbb是符合条件的字符串，
剩下的均为不符合条件的字符串。

假定n和m皆满足：2<=n,m<=1000000000)。

思路：http://blog.csdn.net/kevinkitty_love/article/details/17735903
*/

/*
27、最短摘要生成
同10题
*/

/*
28、实现memcpy函数
29、实现memmove函数
提示：memmove函数要考虑发生重叠的情况。
*/