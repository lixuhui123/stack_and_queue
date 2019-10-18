#include <iostream>
#include <vector>
using namespace std;
int mainohhvm()
{
#if 1
	vector<int> test;
	vector<int>::iterator it;
	it = test.begin();
    it=test.insert(it,5);
   
	//test.push_back(1);
	//test.push_back(2);
	//test.push_back(3);
	//test.push_back(4);
	it = test.begin();
	 it = test.insert(it, 88);
	 cout << test.size()<<endl;
	 cout << test.capacity() << endl;
	for (auto& v : test)
	{
		cout << v << ' ';
	}
#else
	vector<int> myvector(3, 100);
	vector<int>::iterator it;

	it = myvector.begin();
	it = myvector.insert(it, 200);

	myvector.insert(it, 2, 300);

	// "it" no longer valid, get a new one:
	it = myvector.begin();

	vector<int> anothervector(2, 400);
	myvector.insert(it + 2, anothervector.begin(), anothervector.end());

	int myarray[] = { 501,502,503 };
	myvector.insert(myvector.begin(), myarray, myarray + 3);

	cout << "myvector contains:";
	for (it = myvector.begin(); it < myvector.end(); it++)
		cout << " " << *it;
	cout << endl;

#endif
	system("pause"); 
	return 0;
}