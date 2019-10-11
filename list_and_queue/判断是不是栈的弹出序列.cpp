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
		/* ����Ҫѹջ��vector */
		for (auto &vi:pushV)
		{
			stmp.push(vi);
			for (;!stmp.empty()&&stmp.top()==popV[i];++i)
			{
				/* �������ĳ����ǵ��з��֣�ѭ�����������ж���������ʽ�ܷḻ
				�жϲ�������������if��䣬���Ժ�for����while����ʹ��*/
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
	cout << s.empty();*///��Ϊ�յ�ʱ�򷵻�0
	system("pause"); 
	return 0;
}