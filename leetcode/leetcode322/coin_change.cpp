#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;

// class Solution {
// public:
//     int bfs(vector<int>& coins, int amount) {
//         if (coins.size()==0 || amount==0) return -1;

//         queue<pair<int, int> > q; q.push(make_pair(0, 0));

//         int head = 0, tail = 1, tmp = tail;
//         int step = 0;

//         while (!q.empty()) {
//             while (head < tail) {
//                 pair<int, int> ele = q.front(); q.pop(); ++head;
//                 // printf("%8d", ele.second);

//                 if (ele.second > amount) continue;
//                 if (ele.second == amount) return step;

//                 for (int i = 0; i < coins.size(); ++i) {
//                     if (ele.first <= coins[i]) {
//                         q.push(make_pair(coins[i], ele.second+coins[i]));
//                         ++tmp;
//                     }
//                 }
//             }
//             tail = tmp;
//             ++step;
//         }
//         return -1;
//     }

//     int coinChange(vector<int>& coins, int amount) {
//         set<int> s;
//         for (int i = 0; i < coins.size(); ++i) {
//             s.insert(coins[i]);
//         }

//         vector<int> v;
//         set<int>::iterator iter = s.begin();
//         for ( ; iter != s.end(); ++iter) {
//             v.push_back(*iter);
//         }

//         return bfs(v, amount);
//     }
// };


const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 10;
int dp[maxn];

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        dp[0] = 0;
        
        for (int i = 1; i <= amount; ++i) {
            int min_step = INF;
            for (int j = 0; j<coins.size() && i-coins[j]>=0; ++j) {
                min_step = min(min_step, dp[i-coins[j]]+1);
            }
            dp[i] = min_step;
        }
        return dp[amount]>=INF?-1:dp[amount];
    }
};

int main() {
    int a[] = {474, 83, 404, 3};
    vector<int> v(a, a+sizeof(a)/sizeof(a[0]));

    Solution sol;
    cout << sol.coinChange(v, 264) << endl;
    return 0;
}