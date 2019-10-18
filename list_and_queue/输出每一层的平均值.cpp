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
	vector<double> averageOfLevels(TreeNode* root)
	{
		vector<int> lel_val;
		vector<double> res;
		if (root == NULL)
		{
			return res;
		}
		/* 根据层遍历的特点，将它自己和左右孩子入队， */
		TreeNode* cur = root;
		m_qu.push(root);
		int lev_len = 1;
		while (!m_qu.empty())
		{

			for (int i = 0; i < lev_len; ++i)
			{
				//cur = m_qu.back();/*以后应该注意， 此处写错了， */
				cur = m_qu.front();
				int lev_num = m_qu.front()->val;
				lel_val.push_back(lev_num);
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
			//cout << endl;
			double num=figurelev(lel_val);
			res.push_back(num);

			lev_len = m_qu.size();
			lel_val.clear();
		}
		return res;

	}
	double figurelev(vector<int> num)
	{
		double add=0;
		int _size = num.size();
		for (auto&val:num)
		{
			add += val;
		}
		return add / _size;
	}
};
int maindfgh()
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
	vector<double> v;
	v=test.averageOfLevels(t1);
	for (auto&num:v)
	{
		cout << num << ' ';
	}
	system("pause");
	return 0;
}