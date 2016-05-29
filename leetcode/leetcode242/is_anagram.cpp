#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        for (int i = 0; i < s.length(); ++i) {
            ++hashs[s[i]];
            ++hasht[t[i]];
        }

        for (int i = 0; i < maxch; ++i) {
            if (hashs[i] != hasht[i]) {
                return false;
            }
        }
        return true;
    }

private:
    static const int maxch = 128;
    int hashs[maxch], hasht[maxch];
};

int main() {
    return 0;
}