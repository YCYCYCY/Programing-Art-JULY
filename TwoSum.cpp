/*
输入一个数组和一个数字，在数组中查找两个数，
使得它们的和正好是输入的那个数字。

要求时间复杂度是O(N)。如果有多对数字的和等于输入的数字，输出任意一对即可。

例如输入数组1、2、4、7、11、15和数字15。由于4+11=15，因此输出4和11。

解决这类题有以下三种办法：

1、二分（若无序，先排序后二分），时间复杂度总为O(N*log N)，
空间复杂度为O（1）；
2、扫描一遍X-S[i] 映射到一个数组或构造hash表，时间复杂度为O(N)，
空间复杂度为O(N)；
3、两个指针两端扫描（若无序，先排序后扫描），时间复杂度最后为：
有序O(N)，无序O(N log N + N)=O(N log N)，空间复杂度都为O(1)。
*/


/*1、在二元树中找出和为某一值的所有路径,输入一个整数和一棵二元树，
从树的根结点开始往下访问一直到叶结点所经过的所有结点形成一条路径，
然后打印出和与输入整数相等的所有路径。 例如输入整数22和如下二元树
    10  
   /  \
  5    12
 / \
4   7
则打印出两条路径：10, 12和10, 5, 7。 其中，二元树节点的数据结构定义为：

*/
struct node // a node in the binary tree
{
    int m_nValue; // value of node
    node *m_pLeft; // left child of node
    node *m_pRight; // right child of node
};
void branchSum(node*p,int k,int *num,vector<int>&path)
{
	if(p==NULL)
		return ;
	if(p->m_nValue>k)
		return ;
	else if(p->m_nValue==k)
	{
		if(p->m_pLeft==NULL && m_pRight==NULL)
		{
			path.push_back(p->m_nValue);
			for(size_t i=0;i!=path.size();++i)
				cout<<path[i]<<endl;
		}
	}
	else
	{
		path.push_back(p->m_nValue);
		branchSum(p->m_pLeft,k-(p->m_nValue),path);
		branchSum(p->m_pRight,k-(p->m_nValue),path);
	}
}


/*
2、有一个数组a，设有一个值n。在数组中找到两个元素a[i]和a[j]，
使得a[i]+a[j]等于n，求出所有满足以上条件的i和j。
思路：建立一个哈希表保存数组，
*/

/*
3、3-sum问题
给定一个整数数组，判断能否从中找出3个数a、b、c，使得他们的和为0，
如果能，请找出所有满足和为0个3个数对。
*/
/*
4、4-sum问题

给定一个整数数组，判断能否从中找出4个数a、b、c、d，使得他们的和为0，
如果能，请找出所有满足和为0个4个数对。
*/