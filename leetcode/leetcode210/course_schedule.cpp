#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    void dfs_cycle(unordered_map<int, vector<int> > &graph, vector<int> &visit, int course_id, bool &has_cycle) {
        if (visit[course_id] == 1) { has_cycle = true; return; }
        visit[course_id] = 1;
        vector<int>::iterator iter = graph[course_id].begin();
        for ( ; iter != graph[course_id].end(); ++iter) {
            if (has_cycle) return;
            if (visit[course_id] < 2) {
                dfs_cycle(graph, visit, *iter, has_cycle);
            }
        }
        visit[course_id] = 2;
        return;
    }

    bool can_finish(int numCourses, unordered_map<int, vector<int> > &graph) {
        vector<int> visit(numCourses, 0);
        bool has_cycle = false;
        unordered_map<int, vector<int> >::iterator iter = graph.begin();
        for ( ; iter != graph.end(); ++iter) {
            if (has_cycle) return false;
            if (!visit[iter->first]) {
                dfs_cycle(graph, visit, iter->first, has_cycle);
            }
        }
        return true;
    }

    void dfs_order(unordered_map<int, vector<int> > &graph, vector<bool> &visit, int course_id, vector<int> &order) {
        visit[course_id] = true;
        vector<int>::iterator iter = graph[course_id].begin();
        for ( ; iter != graph[course_id].end(); ++iter) {
            if (!visit[*iter]) {
                dfs_order(graph, visit, *iter, order);
            }
        }
        order.push_back(course_id);
        return;
    }

    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
        unordered_map<int, vector<int> > graph;
        for (int i = 0; i < prerequisites.size(); ++i) {
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
        }

        vector<bool> visit(numCourses, false);
        vector<int> order;
        if (!can_finish(numCourses, graph)) return order;

        unordered_map<int, vector<int> >::iterator iter = graph.begin();
        for ( ; iter != graph.end(); ++iter) {
            if (!visit[iter->first]) {
                dfs_order(graph, visit, iter->first, order);
            }
        }
        reverse(order.begin(), order.end());

        unordered_set<int> s;
        for (int i = 0; i < order.size(); ++i) s.insert(order[i]);
        for (int i = 0; i < numCourses; ++i) {
            if (s.find(i) == s.end()) order.push_back(i);
        }
        return order;
    }
};

int main() {
    return 0;
}
