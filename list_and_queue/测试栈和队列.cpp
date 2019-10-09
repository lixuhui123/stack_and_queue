#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int mainds()
{
	stack<int> s;
	queue<int> q;
 	/*s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout << s.top()<<endl;
	s.pop();
	cout << s.top() << endl;*/

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.pop();
	cout << q.front() << ' ' << q.back() << endl<<q.size();
	system("pause"); 
	return 0;
}