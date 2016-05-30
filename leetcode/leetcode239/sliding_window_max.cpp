#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    class Pair {
    public:
        Pair(int st, int nd): first(st), second(nd) {}
        int first, second;
    };

    struct cmp {
        bool operator()(const Pair &p1, const Pair &p2) {
            return p1.second < p2.second;
        }
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<Pair, vector<Pair>, cmp> pq;
        vector<int> v;

        for (int i = 0; i < nums.size(); ++i) {
            pq.push(Pair(i, nums[i]));

            if (pq.size() >= k) {
                Pair p = pq.top();
                while (p.first+k-1 < i) {
                    pq.pop();
                    p = pq.top();
                }
                v.push_back(p.second);
            }  
        }
        return v;
    }
};

int main() {
    int a[] = {1, 3, -1, -3, -2, 3, 6, 7};
    vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;

    Solution sol;
    v = sol.maxSlidingWindow(v, 3);
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}