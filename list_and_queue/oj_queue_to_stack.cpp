#include <iostream>
#include <queue>
using namespace std;
/* 队列实现栈，不要给自己留后路 */
class mystack 
{
	queue<int> m_qu;
public:
	/** initialize your data structure here. */

	mystack() 
	{
		
	}

	/** push element x onto stack. */
	void push(int x) 
	{
		m_qu.push(x);
	}

	/** removes the element on top of the stack and returns that element. */
	int pop()
	{
		//力扣题的漏洞，pop怎么返回int
		 
		queue<int> tmp;
		int val;
		int max = m_qu.size();
		for (int i=0;i<max-1;++i)
		{
			tmp.push(m_qu.front());
			m_qu.pop();
		}
		val = m_qu.front();
		m_qu = tmp;
		return val;
	}

	/** get the top element. */
	int top() 
	{
		return m_qu.back();
	}

	/** returns whether the stack is empty. */
	bool empty() 
	{
		return m_qu.empty();
	}
};

/**
 * your mystack object will be instantiated and called as such:
 * mystack* obj = new mystack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
int main12334()
{
	mystack mystack;
	mystack.push(1);
	mystack.push(2);
	mystack.push(3);
	mystack.push(4);
	cout << mystack.empty()<<endl;
	cout << mystack.pop()<<endl;
	cout << mystack.top();

	system("pause"); 
	return 0;
}