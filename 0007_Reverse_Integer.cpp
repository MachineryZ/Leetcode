#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

/*
class Solution 
{
public:
    int reverse(int x) 
    {
        int res = 0;
        return res;
    }
};*/

int reverse(int x)
{
	int res = 0;
	while(x != 0)
	{
		int tmp = res * 10 + x % 10;
		if(tmp / 10 != res)
			return 0;
		res = tmp;
		x = x/10;
	}
	return res;
}

int main()
{
	while(cin >> x)
		cout << reverse(x) << endl;
	

	return 0;
}