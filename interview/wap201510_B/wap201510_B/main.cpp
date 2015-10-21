#include <cstdio>
#include <set>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;

int n, m;
multiset<int> near[maxn];

int stamp;
int cluster[maxn], father[maxn], kid[maxn];
int top[maxn], idx[maxn], pos[maxn];
int festiveNum;
bool isFestive[maxn];

inline int min(int x, int y) { return x<y ? x : y; }

inline int getD(int u)
{
    if (near[u].size() > 0) return *near[u].begin();
    return INF;
}

struct Edge {
    int v, next;
} edge[maxn * 2];
int edgeNum, head[maxn];

void clearEdge()
{
    edgeNum = 0;
    memset(head, -1, sizeof(head));
	return;
}

inline void addEdgeSub(const int &u, const int &v)
{
    edge[edgeNum].v = v;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
	return;
}

inline void addEdge(const int &u, const int &v)
{
    addEdgeSub(u, v);
    addEdgeSub(v, u);
	return;
}

struct TreeNode {
    int l, r, lc, rc;
    int minL, minR;
} node[maxn * 3];
int nodeNum, tree[maxn];

void initNode(int x)
{
    if (isFestive[pos[node[x].l]]) node[x].minL = node[x].minR = 0;
    else node[x].minL = node[x].minR = getD(node[x].l);
	return;
}

void pushUp(int x)
{
    int L = node[x].lc;
    int R = node[x].rc;
    int mid = (node[x].l + node[x].r) >> 1;
    node[x].minL = min(node[L].minL, node[R].minL + mid + 1 - node[x].l);
    node[x].minR = min(node[R].minR, node[L].minR + node[x].r - mid);
	return;
}

// build tree
int buildTree(int l, int r)
{
    int x = nodeNum++;
    node[x].l = l;
    node[x].r = r;
    if (l == r) { initNode(x); return x; }
    int mid = (l + r) >> 1;
    node[x].lc = buildTree(l, mid);
    node[x].rc = buildTree(mid + 1, r);
    pushUp(x);
    return x;
}

// update tree recursively, keep balanced
void updateTree(int x, int pos)
{
    if (node[x].l == node[x].r) { initNode(x); return; }
    int mid = (node[x].l + node[x].r) >> 1;
    if (pos <= mid) updateTree(node[x].lc, pos);
    else updateTree(node[x].rc, pos);
    pushUp(x);
	return;
}

// query for left tree, binary search, recursively
int queryTreeL(int x, int l, int r)
{
    if (node[x].l==l && node[x].r==r) return node[x].minL;
    int mid = (node[x].l + node[x].r) >> 1;
    if (r <= mid) return queryTreeL(node[x].lc, l, r);
    if (l > mid) return queryTreeL(node[x].rc, l, r);
    int lmin = queryTreeL(node[x].lc, l, mid);
    int rmin = queryTreeL(node[x].rc, mid + 1, r);
    return min(lmin, rmin + mid + 1 - l);
}

// query for right tree, binary search, recursively
int queryTreeR(int x, int l, int r)
{
    if (node[x].l==l && node[x].r==r) return node[x].minR;
    int mid = (node[x].l + node[x].r) >> 1;
    if (r <= mid) return queryTreeR(node[x].lc, l, r);
    if (l > mid) return queryTreeR(node[x].rc, l, r);
    int lmin = queryTreeR(node[x].lc, l, mid);
    int rmin = queryTreeR(node[x].rc, mid + 1, r);
    return min(rmin, lmin + r - mid);
}

// union-find structure
void initRelation(int u, int f = -1)
{
    cluster[u] = 1;
    father[u] = f;
    kid[u] = 0;
    top[u] = u;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if (v != f) {
            initRelation(v, u);
            if (cluster[v] > cluster[kid[u]]) kid[u] = v;
            cluster[u] += cluster[v];
        }
    }
	return;
}

void initIndex(int u, int f = -1)
{
    idx[u] = ++stamp;
    pos[stamp] = u;
    if (kid[u]) {
        top[kid[u]] = top[u];
        initIndex(kid[u], u);
    }
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if (v!=f && v!=kid[u]) initIndex(v, u);
    }
	return;
}

void initHeavy()
{
    stamp = 0;
    initRelation(1);
    initIndex(1);
	return;
}

void buildTrees(int u, int f)
{
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if (v!=f && v!=kid[u]) buildTrees(v, u);
    }
    if (kid[u]) buildTrees(kid[u], u);
    else tree[idx[top[u]]] = buildTree(idx[top[u]], idx[u]);
	return;
}

void buildTrees()
{
    buildTrees(1, -1);
	return;
}

void init()
{
    nodeNum = 0;
    clearEdge();
    memset(isFestive, false, sizeof(isFestive));
	festiveNum = 1; isFestive[1] = true;
    for (int i = 1; i <= n; ++i) near[i].clear();
	return;
}

// update operation, update tree at the same time
void update(int u)
{
    if (!isFestive[u]) {
        isFestive[u] = true;
        ++festiveNum;
    } else return;
    while (true) {
        int t = tree[idx[top[u]]];
        int oldVal = node[t].minL + 1;
        updateTree(t, idx[u]);
        int newVal = node[t].minL + 1;
        u = father[top[u]];
        if (u == -1) break;
        multiset<int> &s = near[idx[u]];
        if (newVal != oldVal) {
            multiset<int>::iterator it = s.find(oldVal);
            if (it != s.end()) s.erase(it);
            if (newVal < INF) s.insert(newVal);
        }
    }
	return;
}

// query operation, and print the result
void query(int u)
{
    if (isFestive[u]) puts("0");
    else {
        int d = 0;
        int ans = INF;
        while (true) {
            int t = tree[idx[top[u]]];
            int l = node[t].l;
            int r = node[t].r;
            ans = min(ans, queryTreeR(t, l, idx[u]) + d);
            ans = min(ans, queryTreeL(t, idx[u], r) + d);
            d += idx[u] - l + 1;
            u = father[top[u]];
            if (u == -1) break;
        }
        printf("%d\n", ans);
    }
	return;
}

int main()
{
    int u, v;
    scanf("%d %d", &n, &m);
    init();
    for (int i = 1; i < n; ++i) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    initHeavy();
    buildTrees();
    while (m--) {
        scanf("%d %d", &u, &v);
        if (u == 1) update(v);
        else query(v);
    }
    return 0;
}

/*
5 5
1 2
1 3
3 4
3 5
2 5
2 3
1 3
2 3
2 4

15 100
1 2
1 3
2 4
2 5
3 6
3 7
4 8
4 9
5 10
5 11
6 12
6 13
7 14
7 15

15 100
1 2
1 3
1 4
1 5
1 6
2 7
2 8
3 9
9 10
9 11
10 15
5 12
12 13
6 14
*/
