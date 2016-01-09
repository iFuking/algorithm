#include <iostream>
#include <string>
using namespace std;

class Periods {
public:
    long long getLongest(int n, string s) {
		if (s.length() < 2) return 0LL;

		/*for (int i = 1; i < s.length(); ++i) {
			string sub_s = s.substr(0, i+1);
			int max_pre = 0;
			for (int j = sub_s.length()/2; j < sub_s.length(); ++j) {
				string str = sub_s.substr(0, j)+sub_s.substr(0, j);
				if (sub_s == str.substr(0, sub_s.length())) max_pre = j;
			}
			cnt += max_pre;
		}*/
		int max_sub = 0;
		for (int i = s.length()/2; i < s.length(); ++i) {
			string str = s.substr(0, i)+s.substr(0, i);
			if (s==str.substr(0, s.length()) && str.length()>max_sub) max_sub = i;
		}
		string sub_s = s.substr(0, max_sub);

		int next_max = 0;
		for (int i = sub_s.length()/2; i < sub_s.length(); ++i) {
			string str = sub_s.substr(0, i)+sub_s.substr(0, i);
			if (sub_s==str.substr(0, sub_s.length()) && str.length()>next_max) next_max = i;
		}

		int delta = max_sub-next_max;
		if (delta == 0) return 0LL;
		int cnt = max_sub/delta;
		return 1LL*delta*delta*(1LL+cnt)*cnt/2LL;
    }
};

int main()
{
	Periods sol;
	cout << sol.getLongest(8, "babababa") << endl;
	return 0;
}