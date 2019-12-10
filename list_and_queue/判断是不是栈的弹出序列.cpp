#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV)
	{
		/* pushV��������ջ���� popVҪ�жϵĳ�ջ���� */
		stack<int> stmp;/* Ҫ����ջ�������ջ */
		int i=0;
		/* ����Ҫѹջ��vector */
		for (auto &vi:pushV)
		{
			stmp.push(vi);/* ��Ԫ����ջ */
			for ( ;!stmp.empty()&&stmp.top()==popV[i] ; ++i)
			{
				/* �ڳ�ջ������Ѱ����ջ��Ԫ����ͬ��Ԫ�� */
				stmp.pop();
			}
		}
		return stmp.empty();/* ͨ���ж��ܷ�ջ�е�Ԫ�س��꣬����ܳ���
							�Ǿ�����ȷ�ĳ�ջ����*/
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
/* �������ĳ����ǵ��з��֣�ѭ�����������ж���������ʽ�ܷḻ
				�жϲ�������������if��䣬���Ժ�for����while����ʹ��*/