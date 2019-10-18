#include <iostream>
#include <queue>
#include<stack>
using namespace std;
/* 从本题总结的经验来看，如果实现起来困难的话就想别的方法，
方法绝对不止一种，还有画图自己演示，不要老是在脑子里面空想，画出来或者写出来效果会更好、
这是一个帮助一个小白成为老手的方法*/
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
class Solution
{
	queue<TreeNode *> m_qu;
 
public:
	void Mirror(TreeNode * pRoot)
	{

		if (pRoot == NULL)
		{
			return ;
		}
		
		TreeNode* cur =pRoot;
		m_qu.push(cur);
		int lev_len = 1;
		while (!m_qu.empty())
		{

			 
			 
				cur = m_qu.front();
				 
				if (cur->left||cur->right)
				{
					TreeNode * tmp  =cur->left;
					cur->left = cur->right;
					cur->right = tmp;
					 
				}
				//cout << m_qu.front()->val;
				 
				if (cur->left)
				{
					m_qu.push(cur->left);
					 
				}
				 
				if (cur->right)
				{
					m_qu.push(cur->right);
				}

				m_qu.pop();
 
			 
  
		}
	}
};
int main()
{
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t4 = new TreeNode(4);
	TreeNode* t5 = new TreeNode(5);
	TreeNode* t6 = new TreeNode(6);

	t1->left = t2;
	t1->right = t3;
	t1->left->left = t4;
	t1->left->right = t5;
	t1->left->left->left = t6;
	Solution test;
	test.Mirror(t1);
	system("pause"); 
	return 0;
}
