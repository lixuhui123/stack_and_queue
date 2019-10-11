#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <stack>
#include <cstdlib>
/* ��׺���ʽ */
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
			/* �ж�string�ĵ�һ���ַ��ǲ������֣���ר�ŵĺ���isdigit,
			��Ȼ��һ����������ʱҲ�п����Ǹ��������Ǹ���һ�������������������ϵ�
			�ַ�����ô�Ϳ����ó���ȥ�жϣ�����*/
			if (isdigit(vsi[0])||vsi.size()>1)
			{
				/* ��������ջ */
				tmp.push(atoi(vsi.c_str()));
			}
			else
			{
				/* ���Ƿ��ŵ�ʱ��ȡ��ջ����ǰ����Ԫ�أ�ִ�в���������������� */
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
		/* ���ؽ�� */
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