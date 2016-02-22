#include <iostream>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) ans = 26*ans + (s[i]-'A'+1);
        return ans;
    }
};

int main()
{
    return 0;
}
