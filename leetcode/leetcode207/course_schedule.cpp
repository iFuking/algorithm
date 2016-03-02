#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void dfs(unordered_map<int, vector<int> > &graph, vector<int> &visit, int course_id, bool &has_cycle) {
        if (visit[course_id] == 1) { has_cycle = true; return; }
        visit[course_id] = 1;
        vector<int>::iterator iter = graph[course_id].begin();
        for ( ; iter != graph[course_id].end(); ++iter) {
            if (has_cycle) return;
            if (visit[course_id] < 2) dfs(graph, visit, *iter, has_cycle);
        }
        visit[course_id] = 2;
        return;
    }

    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<int> visit(numCourses, 0);
        unordered_map<int, vector<int> > graph;
        vector<pair<int, int> >::iterator iter = prerequisites.begin();
        for ( ; iter != prerequisites.end(); ++iter) {
            graph[iter->second].push_back(iter->first);
        }

        bool has_cycle = false;
        unordered_map<int, vector<int> >::iterator ite = graph.begin();
        for ( ; ite != graph.end(); ++ite) {
            if (has_cycle) return false;
            if (!visit[ite->first]) dfs(graph, visit, ite->first, has_cycle);
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<pair<int, int> > v;
    v.push_back(make_pair(0, 1));
    v.push_back(make_pair(3, 1));
    v.push_back(make_pair(1, 3));
    v.push_back(make_pair(3, 2));
    cout << sol.canFinish(4, v) << endl;
}
