#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main()
{
	set<string> strsets;
	vector<string> strvec;
	string s;
	while (cin >> s)
	{
		strvec.push_back(s);
		strsets.insert(s);
	}
	vector<string>::iterator iter = strvec.begin();
	while (iter != strvec.end())
	{
		s = *iter;
		if (s.length() > 1)
		{
			string subh, subt;
			for (int i = 1; i < s.length(); i++)
			{
				subh = s.substr(0, i);
				subt = s.substr(i, s.length());
				if (strsets.count(subh) && strsets.count(subt))
				{
					cout << *iter << endl;
					break;
				}
			}
		}
		iter++;
	}
	return 0;
}