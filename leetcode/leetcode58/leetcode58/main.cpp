#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
	vector<string> &split(const string &s, char delim, vector<string> &elems) {
		int lens = s.length();
		string ele = "";
		for (int i = 0; i < lens; ++i) {
			if (s[i] != ' ') ele += s[i];
			else {
				if (ele == "") continue;
				elems.push_back(ele); ele = "";
			}
		}
		if (ele != "") elems.push_back(ele);
		return elems;
	}

    int lengthOfLastWord(string s) {
        vector<string> pieces;
		pieces = split(s, ' ', pieces);
		if (pieces.size() == 0) return 0;
		return pieces[pieces.size()-1].size();
    }
};

int main()
{
	Solution sol;
	cout << sol.lengthOfLastWord("Hello World") << endl;
	return 0;
}