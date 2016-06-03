#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v;
        for (int i = 0; i <= num; ++i) {
        	int cnt = 0, n = i;
        	while (n) {
        		if (n&1) ++cnt;
        		n >>= 1;
        	}
        	v.push_back(cnt);
        }
        return v;
    }
};

int main() {
	Solution sol;
	vector<string> v = sol.findRepeatedDnaSequences("");
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}