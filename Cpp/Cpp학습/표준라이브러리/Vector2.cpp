#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b)
{
	return a > b;
};

void main()
{
	vector<int> x = { 1,5,8,9,11,21,32,28,25,14,12 };
	vector<int> y;
	y.push_back(7);
	y.push_back(3);
	y.push_back(5);
	y.push_back(7);
	y.push_back(6);

	//sort(y.begin(), y.end());
	sort(y.begin(), y.end(), compare);

	for (auto i = 0; i < y.size(); i++)
	{
		cout << y[i] << endl;
	}
}