#include <iostream>
#include <functional>//仿函数
#include <algorithm>//算法
#include <queue>
using namespace std;
class commit
{
	/* 仿函数类 ,让类型回调，重载()*/
public:
	bool operator()(int a, int b)
	{
		return a < b;
	}
};
int main()
{
	vector<int> v{ 1,5,26,2 };

	priority_queue<int,vector<int>,less<int>> pqu(v.begin(),v.end());/*小堆  */
	/* 适配器less<int>,大堆greater<int>小 ,vector<int>用vector构造,容器适配器*/
	priority_queue<int, vector<int>, commit> pqu1(v.begin(), v.end());/*小堆  */

	cout << pqu1.top();
	system("pause"); 
	return 0;
}