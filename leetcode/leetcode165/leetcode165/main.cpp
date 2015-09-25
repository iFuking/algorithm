#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

class Solution {
public:
	vector<string> &split(const string &s, char delim, vector<string> &elems) {
		stringstream ss(s);
		string item;
		while(getline(ss, item, delim)) {
			elems.push_back(item);
		}
		return elems;
	}

    int compareVersion(string version1, string version2) {
        vector<string> item1, item2;
		vector<int> v1, v2;
		item1 = split(version1, '.', item1);
		for (int i = 0; i < item1.size(); ++i) v1.push_back(atoi(item1[i].c_str()));
		item2 = split(version2, '.', item2);
		for (int i = 0; i < item2.size(); ++i) v2.push_back(atoi(item2[i].c_str()));

		int i;
		for (i = 0; i<v1.size() && i<v2.size(); ++i) {
			if (v1[i] < v2[i]) return -1;
			else if (v1[i] > v2[i]) return 1;
		}
		int sum = 0;
		if (i==v1.size() && i==v2.size()) return 0;
		else if (i == v1.size()) {
			for ( ; i < v2.size(); ++i) sum += v2[i];
			if (sum == 0) return 0;
			return -1;
		} else if (i == v2.size()) {
			for ( ; i < v1.size(); ++i) sum += v1[i];
			if (sum == 0) return 0;
			return 1;
		}
    }
};

int main()
{
	Solution sol;
	sol.compareVersion("1.0", "1");
	return 0;
}