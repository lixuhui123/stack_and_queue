#include <iostream>
#include <stack>
using namespace std;
template<class T>
class stacktoquueu 
{
	stack<T> m_stk1;
public:
	stacktoquueu()
	{

	}
	void qu_push(T x)
	{
		m_stk1.push(x);
	}
	void qu_pop()
	{
		/* 队列的删除是从队头删 */
		stack<T> m_stk2;
		while (m_stk1.size()>1)
		{
			m_stk2.push(m_stk1.top());
			m_stk1.pop();
		}
		m_stk1.pop();
		while (m_stk2.size())
		{
			m_stk1.push(m_stk2.top());
			m_stk2.pop();
		}
	}
	T qu_front()
	{
		/* 取队列的头 */
		stack<T> m_stk2;
		while (m_stk1.size() > 1)
		{
			m_stk2.push(m_stk1.top());
			m_stk1.pop();
		}
		int tmp = m_stk1.top();

		while (m_stk2.size())
		{
			m_stk1.push(m_stk2.top());
			m_stk2.pop();
		}
		return tmp;
	}
	T qu_back()
	{
		return m_stk1.top();
	}

};
int main()
{
	stacktoquueu<int> qu;
	qu.qu_push(1);
	qu.qu_push(2);
	qu.qu_push(3);
	qu.qu_push(4);
	qu.qu_pop();
	qu.qu_pop();
	qu.qu_push(5);
	cout << qu.qu_front() << ' ' << qu.qu_back() << endl;
	system("pause"); 
	return 0;
}