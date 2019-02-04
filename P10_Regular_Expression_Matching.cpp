#include <iostream>
#include <cstring>

using namespace std;

bool isMatch(string s, string p)
{
	bool res = true;
	if(p.empty())
		return s.empty();
	if(p.size() == 1)
		return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));
	if(p[1] != '*')
	{
		if(s.empty())
			return false;
		return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
	}
	while(!s.empty() && (s[0] == p[0] || p[0] == '.'))
	{
		if(isMatch(s, p.substr(2)))
			return true;
		s = s.substr(1);
	}
	return isMatch(s, p.substr(2));
}



int main()
{
	string s, p;
	while(cin >> s >> p)
		cout << isMatch(s, p) << endl;
	return 0;
}