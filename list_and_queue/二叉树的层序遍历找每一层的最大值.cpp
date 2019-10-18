#include <iostream>
#include <queue>
using namespace std;

 
struct TreeNode 
{
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
	{
		//初始化列表
	}
};
 
class Solution 
{
	queue<TreeNode*> m_qu;
public:
	vector<int> levelOrder(TreeNode* root)
	{
		 vector<int> max;
		if (root==NULL)
		{
			return max;
		}
		
		int lev_len=1;/*第一层肯定只有一个 */
		/* 根据层遍历的特点，将它自己和左右孩子入队， */
		TreeNode* cur = root;
		m_qu.push(root);
		while (!m_qu.empty())
		{ 
			int lev_max=m_qu.front()->val;
			for (int i=0;i<lev_len;++i)
			{
				//cur = m_qu.back();/*以后应该注意， 此处写错了， */
				cur = m_qu.front();

               
				//cout << m_qu.front()->val;
				if (lev_max < m_qu.front()->val)
				{
					lev_max = m_qu.front()->val;
				}
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
			//cout << endl;
			max.push_back(lev_max);
			lev_len = m_qu.size();
		}
		    

		return max;

	}
};
int main1568()
{
	TreeNode* t1=new TreeNode(1);
	TreeNode* t2=new TreeNode(2);
	TreeNode* t3= new TreeNode(3);
	TreeNode* t4 = new TreeNode(4);
	TreeNode* t5 = new TreeNode(5);
	TreeNode* t6 = new TreeNode(6);

	t1->left=t2;
	t1->right = t3;
	t1->left->left = t4;
	t1->left->right = t5;
	t1->left->left->left = t6;
	Solution test;
	vector<int> v;
	v=test.levelOrder(t1);
	for (auto&j : v)
	{
		cout << j << ' ';
	}
	system("pause"); 
	return 0;
}