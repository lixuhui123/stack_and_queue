#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void filetest()
{
	/*ifstream ifs("1.txt");
	char str[20] = "lixuhui hhah";
	ifs.getline(str, 19);

	cout << str;

	ifs.close();*/
	ifstream ifs("test.txt", ifstream::in);

	while (ifs.good())
		cout << (char)ifs.get();

	ifs.close();


}

void stringtest()
{
	/* 输入string流 */
	ostringstream oss;

	oss << "hello,world!";
	cout << oss.str();
	//roll
	/* 输出string流 */
	vector<int> v;
	string line;
	int tmp;
	getline(cin, line);
	istringstream iss(line );
	while (iss>>tmp)
	{
		v.push_back(tmp);
	}
	for (auto&i:v)
	{
		cout << i<<endl;
	}
}

int main()
{
	stringtest();
	//filetest();
	//cerr << "error";
	system("pause");
	return 0;
}