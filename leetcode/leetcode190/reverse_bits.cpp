#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rev = 0;
        for (int i = 0; i < 32; ++i) {
        	if (n&1) {
        		rev += (1U<<(31-i));
        	}
        	n >>= 1;
        }
        return rev;
    }
};

int main() {
	Solution sol;
	cout << sol.reverseBits(0x80000000) << endl;
	return 0;
}