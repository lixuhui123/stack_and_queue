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
		/* 层序遍历 ，先将头入队*/
		queue<TreeNode*> qu;
		TreeNode* cur=root;
		qu.push(root);
		int len = 1;
		/* 层序遍历 */
		while ( !qu.empty())
		{
			/* 控制压进vector的元素个数 */
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