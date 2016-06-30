#include <iostream>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    bool func_block(queue<pair<int, int> > &q, pair<int, int> &pp) {
        if (pp.first==c || pp.second==c || pp.first+pp.second==c) {
            return true;
        }
        if (uset.find(pp) == uset.end()) {
            uset.insert(pp);
            q.push(pp);
        }
        return false;
    }

    bool water_operation(queue<pair<int, int> > &q, pair<int, int> &p) {
        pair<int, int> pp;

        // 1. fill first
        pp.first = a; pp.second = p.second;
        if (func_block(q, pp)) return true;

        // 2. fill second
        pp.first = p.first; pp.second = b;
        if (func_block(q, pp)) return true;

        // 3. empty first
        pp.first = 0; pp.second = p.second;
        if (func_block(q, pp)) return true;

        // 4. empty second
        pp.first = p.first; pp.second = 0;
        if (func_block(q, pp)) return true;

        // 5. pour first to second
        if (p.first <= b-p.second) {
            pp.first = 0;
            pp.second += p.first;
        } else {
            pp.first -= (b-p.second);
            pp.second = b;
        }
        if (func_block(q, pp)) return true;

        // 6. pour second to first
        if (p.second <= a-p.first) {
            pp.first += p.second;
            pp.second = 0;
        } else {
            pp.first = a;
            pp.second -= (a-p.first);
        }
        if (func_block(q, pp)) return true;

        return false;
    }

    bool bfs() {
        queue<pair<int, int> > q;
        q.push(make_pair(0, 0));
        uset.insert(make_pair(0, 0));

        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            if (water_operation(q, p)) {
                return true;
            }
        }
        return false;
    }

    bool canMeasureWater(int x, int y, int z) {
        a = x; b = y; c = z;
        return bfs();
    }

private:
    int a, b, c;
    set<pair<int, int> > uset;
};

int main() {
    Solution sol;
    while (true) {
        int x, y, z; cin >> x >> y >> z;
        cout << sol.canMeasureWater(x, y, z) << endl;
    }
    return 0;
}