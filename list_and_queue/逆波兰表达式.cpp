#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <stack>
#include <cstdlib>
/* 后缀表达式 */
using namespace std;
class Solution 
{
	stack<int> tmp;
	int a;
	int b;

public:
	int evalRPN(vector<string>& tokens) 
	{
		for (auto & vsi:tokens)
		{
			/* 判断string的第一个字符是不是数字，有专门的函数isdigit,
			当然第一个不是数字时也有可能是负数，但是负数一定有两个或者两个以上的
			字符，那么就可以用长度去判断，如下*/
			if (isdigit(vsi[0])||vsi.size()>1)
			{
				/* 将数字入栈 */
				tmp.push(atoi(vsi.c_str()));
			}
			else
			{
				/* 当是符号的时候，取出栈顶的前两个元素，执行操作，并将结果存入 */
				a = tmp.top();
				tmp.pop();
				b = tmp.top();
				switch (vsi[0])
				{
				case '+':
					tmp.top() = b + a;
					break;
				case '-':
					tmp.top() = b - a;

					break;
				case '*':
					tmp.top() = b * a;

					break;
				case '/':
					tmp.top() = b / a;

					break;
				}
			}
		}
		/* 返回结果 */
		return tmp.top();
	}
};
int main234()
{
	vector<string> vs{ "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
	Solution test;
	cout << test.evalRPN(vs);
	system("pause"); 
	return 0;
}