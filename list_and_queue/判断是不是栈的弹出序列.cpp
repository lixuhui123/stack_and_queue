#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV)
	{
		/* pushV给定的入栈序列 popV要判断的出栈序列 */
		stack<int> stmp;/* 要让入栈序列入的栈 */
		int i=0;
		/* 遍历要压栈的vector */
		for (auto &vi:pushV)
		{
			stmp.push(vi);/* 将元素入栈 */
			for ( ;!stmp.empty()&&stmp.top()==popV[i] ; ++i)
			{
				/* 在出栈序列中寻找与栈顶元素相同的元素 */
				stmp.pop();
			}
		}
		return stmp.empty();/* 通过判断能否将栈中的元素出完，如果能出完
							那就是正确的出栈序列*/
	}
};
int main()
{
	vector<int> puv{ 1,2,3,4,5 };
	vector<int> pov{ 4,5,3,2,1 };
	Solution test;
	cout << test.IsPopOrder(puv, pov);
	system("pause"); 
	return 0;
}
/* 从这样的程序是当中发现，循环控制语句的判断条件的形式很丰富
				判断并不仅仅局限于if语句，可以和for或者while搭配使用*/