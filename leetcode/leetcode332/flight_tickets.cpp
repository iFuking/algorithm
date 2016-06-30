#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    void dfs(string from, bool &found, vector<string> &p) {
        if (found) return;
        if (p.size() == n+1) {
            found = true;
            path = p;
            return;
        }

        auto iter = from_to[from].begin();
        for ( ; iter != from_to[from].end(); ++iter) {
            pair<string, string> t = make_pair(from, *iter);
            if (cnt[t] > 0) {
                --cnt[t]; p.push_back(*iter);
                dfs(*iter, found, p);
                p.pop_back(); ++cnt[t];
            }
        }
        return;
    }

    vector<string> findItinerary(vector<pair<string, string> > tickets) {
        n = tickets.size();
        // cout << n << endl;
        for (int i = 0; i < tickets.size(); ++i) {
            from_to[tickets[i].first].push_back(tickets[i].second);
            ++cnt[tickets[i]];
        }

        auto iter = from_to.begin();
        for ( ; iter != from_to.end(); ++iter) {
            // cout << iter->first << ": ";
            sort(iter->second.begin(), iter->second.end());

            // auto it = iter->second.begin();
            // for ( ; it != iter->second.end(); ++it) {
            //     cout << *it << ",";
            // }
            // cout << endl;
        }

        bool found = false;
        vector<string> p; p.push_back("JFK");
        dfs("JFK", found, p);
        
        return path;
    }

private:
    int n;
    map<string, vector<string> > from_to;
    map<pair<string, string>, int> cnt;
    vector<string> path;
};

int main() {
    vector<pair<string, string> > v;
    v.push_back(make_pair("MUC", "LHR"));
    v.push_back(make_pair("JFK", "MUC"));
    v.push_back(make_pair("SFO", "SJC"));
    v.push_back(make_pair("LHR", "SFO"));
    // for (int i = 0; i < v.size(); ++i) {
    //     cout << v[i].first << "," << v[i].second << endl;
    // }

    Solution sol;
    vector<string> path = sol.findItinerary(v);
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i] << ",";
    }
    return 0;
}