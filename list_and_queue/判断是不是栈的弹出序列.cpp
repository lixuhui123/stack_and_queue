#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV)
	{
		stack<int> stmp;
		int i=0;
		/* 遍历要压栈的vector */
		for (auto &vi:pushV)
		{
			stmp.push(vi);
			for (;!stmp.empty()&&stmp.top()==popV[i];++i)
			{
				/* 从这样的程序是当中发现，循环控制语句的判断条件的形式很丰富
				判断并不仅仅局限于if语句，可以和for或者while搭配使用*/
				stmp.pop();
			}
		}
		return stmp.empty();
	}
};
int mainnbse()
{
	vector<int> puv{ 1,2,3,4,5 };
	vector<int> pov{ 4,5,3,2,1 };
	Solution test;
	cout << test.IsPopOrder(puv, pov);
	/*stack<int> s;
	s.push(1);
	s.push(2);
	cout << s.empty();*///不为空的时候返回0
	system("pause"); 
	return 0;
}