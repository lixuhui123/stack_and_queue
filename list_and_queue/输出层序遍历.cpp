#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) 
		{}
		
	};
public:
	vector<vector<int>> levelOrder(TreeNode* root) 
	{
		vector<vector<int>> res;
		if (!root)
		{
			return res;
		}
		vector<int> vtmp;
		/* ������� ���Ƚ�ͷ���*/
		queue<TreeNode*> qu;
		TreeNode* cur=root;
		qu.push(root);
		int len = 1;
		/* ������� */
		while ( !qu.empty())
		{
			/* ����ѹ��vector��Ԫ�ظ��� */
			for (int i = 0; i < len; ++i)
			{
				cur = qu.front();
				vtmp.push_back(cur->val);
				qu.pop();
				if (cur->left)
				{
					qu.push(cur->left);
				}
				if (cur->right)
				{
					qu.push(cur->right);
				}
			}
			res.push_back(vtmp);
			vtmp.clear();
			len = qu.size();
		}
		return res;

	}
};
int main()
{
	
	system("pause"); 
	return 0;
}