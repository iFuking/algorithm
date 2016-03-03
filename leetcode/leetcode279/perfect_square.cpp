#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int b_search(int n, vector<int> &sq) {
        int left = 0, right = sq.size()-1;
        while (left <= right) {
            int mid = (left+right) >> 1;
            if (sq[mid] < n) left = mid+1;
            else if (sq[mid] > n) right = mid-1;
            else return mid;
        }
        return right;
    }

    int bfs(int n, vector<int> &sq) {
        int head = 0, tail = 1, tmp = tail, step = 0;
        queue<int> q; q.push(n);
        while (!q.empty()) {
            ++step;
            while (head < tail) {
                int remain = q.front(); q.pop(); ++head;
                int index = b_search(remain, sq);
                for (int i = index; i >= 0; --i) {
                    if (remain-sq[i] == 0) return step;
                    q.push(remain-sq[i]); ++tmp;
                }
            }
            tail = tmp;
        }
        return step;
    }

    int numSquares(int n) {
        vector<int> sq;
        for (int i = 1; i*i <= n; ++i) sq.push_back(i*i);
        return bfs(n, sq);
    }
};

int main() {
    Solution sol;
    while (true) {
        int n; cin >> n;
        cout << sol.numSquares(n) << endl;
    }
    return 0;
}
