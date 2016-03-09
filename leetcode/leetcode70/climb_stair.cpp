#include <iostream>
using namespace std;

const int maxn = 1e3 + 10;
int dp[maxn];

class Solution {
public:
    int climbStairs(int n) {
        if (n==0 || n==1) return 1;
        if (dp[n]) return dp[n];
        return dp[n] = climbStairs(n-1)+climbStairs(n-2);
    }
};

int main() {
    return 0;
}
