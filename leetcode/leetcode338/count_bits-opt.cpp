#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v(num+1);
        for (int i = 1; i <= num; ++i) {
        	// easy to understand
        	v[i] = v[i>>1] + i&1;
        	// v[i] = v[i&(i-1)] + 1;
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