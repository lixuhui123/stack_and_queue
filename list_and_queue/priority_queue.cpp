#include <iostream>
#include <functional>//�º���
#include <algorithm>//�㷨
#include <queue>
using namespace std;
class commit
{
	/* �º����� ,�����ͻص�������()*/
public:
	bool operator()(int a, int b)
	{
		return a < b;
	}
};
int main()
{
	vector<int> v{ 1,5,26,2 };

	priority_queue<int,vector<int>,less<int>> pqu(v.begin(),v.end());/*С��  */
	/* ������less<int>,���greater<int>С ,vector<int>��vector����,����������*/
	priority_queue<int, vector<int>, commit> pqu1(v.begin(), v.end());/*С��  */

	cout << pqu1.top();
	system("pause"); 
	return 0;
}