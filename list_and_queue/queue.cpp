#include <iostream>
#include <queue>
#include <string>
using namespace std;
int mainswddzx()
{
#if 0
	queue<int> qu;
	qu.push(2);
	cout << qu.size()<<endl;
#else
	string st;
	st.push_back('3');
	cout << st.size()<<endl;
	cout << st.capacity() << endl;
#endif
	system("pause"); 
	return 0;
}