#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int myAtoi(string str)
{
	int res = 0;
	int i = 0;
	bool neg_flag = false;
	while(str[i] == ' ' && i < str.size())
		i++;
	if(i == str.size())
		return 0;
	if(str[i] == '-')
	{
		neg_flag = true;
		i++;
	}
	else if(str[i] == '+')
	{
		neg_flag = false;
		i++;
	}
	else if(str[i] < '0' || str[i] > '9')
		return 0;
	while(str[i] <= '9' && str[i] >= '0' && i < str.size())
	{
		int tmp = res * 10 + (str[i] - '0');
		if(tmp / 10 != res && neg_flag == false)
			return (INT_MAX);
		else if(tmp / 10 != res && neg_flag == true)
			return (INT_MIN);
		res = tmp;
		i++;
	}
	return neg_flag ? -res : res;
}

int main()
{
	string str;
	while(cin >> str)
	{
		cout << myAtoi(str) << endl;
	}
	return 0;
}