#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
		if (s.length() == 0) return;

		vector<string> words; string word = "";
		for (int i = 0; i < s.length(); ++i) {
			if (s[i]==' ' && word.length()>0) { words.push_back(word); word = ""; }
			else if (s[i] != ' ') word += s[i];
		}
		if (word != "") words.push_back(word);
		
		s = "";
		if (words.size() == 0) return;
		for (int i = words.size()-1; i > 0; --i) { s += words[i]; s += " "; }
		s += words[0];
		return;
    }
};

int main()
{
	Solution sol; string s = "    ";
	sol.reverseWords(s);
	cout << s << endl;
	return 0;
}