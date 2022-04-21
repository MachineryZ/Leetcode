#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

bool isPalindrome(int x)
{
	int y = 0;
	if(x == (1<<31) || x < 0)
		return 0;
	int xxx = x;
	while(x)
	{
		y = y * 10 + x % 10;
		x = x/10;
	}
	cout << y << endl;
	bool res = false;
	if(xxx == y)
		res = true;
	else
		res = false;
	return res;
}

int main()
{
	int x;
	while(cin >> x)
		cout << isPalindrome(x) << endl;
	return 0;
}