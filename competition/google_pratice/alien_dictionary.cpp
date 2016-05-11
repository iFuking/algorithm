#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void dfs(map<char, vector<char> > &adj, char vertex, vector<bool> &visit, vector<char> &rev_order) {
    visit[vertex] = true;
    vector<char>::iterator iter = adj[vertex].begin();
    for ( ; iter != adj[vertex].end(); ++iter) {
        if (!visit[*iter]) {
            dfs(adj, *iter, visit, rev_order);
        }
    }
    rev_order.push_back(vertex);
    return;
}

void alien_dictionary(vector<string> &dict) {
    if (dict.size() < 2) return;

    map<char, vector<char> > adj;

    for (int i = 0; i < dict.size()-1; ++i) {
        for (int j = 0; j < min(dict[i].length(), dict[i+1].length()); ++j) {
            if (dict[i][j] != dict[i+1][j]) {
                adj[dict[i][j]].push_back(dict[i+1][j]);
                break;
            }
        }
    }


    vector<bool> v(256, false);
    vector<char> top_order;

    map<char, vector<char> >::iterator iter = adj.begin();
    for ( ; iter != adj.end(); ++iter) {
        if (!v[iter->first]) {
            vector<char> rev_order;
            dfs(adj, iter->first, v, rev_order);

            for (int i = 0; i < rev_order.size(); ++i) {
                top_order.push_back(rev_order[i]);
            }
        }
    }

    reverse(top_order.begin(), top_order.end());

    for (int i = 0; i < top_order.size(); ++i) {
        cout << top_order[i];
    }
    cout << endl;
    return;
}

void solve() {
    string s[] = {
        "wrt",
        "wrf",
        "er",
        "ett",
        "rftt"
    };
    vector<string> v;
    for (int i = 0; i < sizeof(s)/8; ++i) {
        v.push_back(s[i]);
        // cout << s[i] << endl;
    }

    alien_dictionary(v);
    return;
}

int main() {
    solve();
    return 0;
}