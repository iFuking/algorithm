#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

const int maxn = 1e3 + 10;
bool visit[maxn];

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {

    }
};

int main()
{
    vector<UndirectedGraphNode *> v0, v1, v2;
    UndirectedGraphNode *node0 = new UndirectedGraphNode(0);
    UndirectedGraphNode *node1 = new UndirectedGraphNode(1);
    UndirectedGraphNode *node2 = new UndirectedGraphNode(2);
    v0.push_back(node1); v0.push_back(node2);
    v1.push_back(node2);
    v2.push_back(node2);
    node0->neighbors = v0; node1->neighbors = v1; node2->neighbors = v2;
    return 0;
}
