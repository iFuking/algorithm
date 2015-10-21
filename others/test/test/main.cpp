#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
const int N = 100001;
const int INF = 0x3f3f3f3f;
vector<int> ed[N];
struct Node {
	int ld, rd; // most left festive city, most right festive city
	int lc, rc; // child
	int l, r; // left index, right index;
};
Node tr[N*6]; // segment tree
int totNode, indx; // total node, city index
int size[N], son[N]; // sub-tree node number, weight son
int top[N], leader[N]; // the link's top node in segmentTree, the link's top city
int pos[N], fa[N]; // the index id of the city in a link, the father of city
int idNode[N], posTree[N];

inline int min(int x, int y) {
	return x<y?x:y;
}
/*-----segmentTree operations---------*/
//build segmentTree: node id, left, right
void buildTree(int f, int l, int r) {
	tr[f].ld = tr[f].rd = INF;
	tr[f].l = l;
	tr[f].r = r;
	if(l == r) { // leaf node
		tr[f].lc = tr[f].rc = -1;
		posTree[idNode[l]] = f;
	} else {
		tr[f].lc = totNode++;
		tr[f].rc = totNode++;
		int mid = l+r >> 1;
		buildTree(tr[f].lc, l, mid);
		buildTree(tr[f].rc, mid+1, r);
	}
}
// update segmentTree: node id, update position, distance, light son distance
void updateTree(int f, int p, int dis) {
	if(tr[f].l == tr[f].r && tr[f].l == p) { // found it
		tr[f].ld = tr[f].rd = min(tr[f].ld, dis);
		return;
	}
	int mid = tr[f].l+tr[f].r >> 1;
	if(p <= mid) { // on the left
		updateTree(tr[f].lc, p, dis);
		tr[f].ld = min(tr[f].ld, tr[tr[f].lc].ld);
		tr[f].rd = min(tr[f].rd, tr[f].r-mid+tr[tr[f].lc].rd);
	} else { // on the right
		updateTree(tr[f].rc, p, dis);
		tr[f].ld = min(tr[f].ld, mid-tr[f].l+1+tr[tr[f].rc].ld);
		tr[f].rd = min(tr[f].rd, tr[tr[f].rc].rd);
	}
}
// query segmentTree: node id, query position
int queryTree(int f, int p) {
	if(tr[f].l == p && tr[f].r == p) // found it
		return tr[f].ld;
	int mid = tr[f].l+tr[f].r >> 1;
	int ans = INF;
	if(p <= mid) { // left 
		ans = min(ans, queryTree(tr[f].lc, p));
		ans = min(ans, mid+1-p+tr[tr[f].rc].ld);
	} else { // right
		ans = min(ans, queryTree(tr[f].rc, p));
		ans = min(ans, p-mid+tr[tr[f].lc].rd);
	}
	return ans;
}
/*---------------------------------*/

// calculate some array: root id, father id
void dfs(int x, int f) {
	fa[x] = f;
	size[x] = 1;
	son[x] = -1;
	for(vector<int>::iterator it = ed[x].begin(); it != ed[x].end(); it++) {
		if(*it == f) continue;
		dfs(*it, x);
		size[x] += size[*it];
		if(son[x] == -1 || size[son[x]] < size[*it])
			son[x] = *it;
	}
}
// build segmenttree: root id, father id
void build(int x, int f) {
	int l = indx;
	// get the weight link
	for(int y = x; y != -1; y = son[y]) {
		leader[y] = x;
		top[y] = totNode;
		idNode[indx] = y;
		pos[y] = indx++;
	}
	// a weight link is built a segment tree
	buildTree(totNode++, l, indx-1);
	// get the light son, and build other weight link
	for(int y = x; y != -1; y = son[y]) {
		for(vector<int>::iterator it = ed[y].begin(); it != ed[y].end(); it++) {
			if(*it == f || *it == son[y]) continue;
			build(*it, y);
		}
		f = y;
	}
}
// insert a festive city: festive city id
void insert(int x) {
	// update from x to x's ancestors
	for(int y = x, dis = 0; y != -1; y = fa[leader[y]]) {
		if(dis >= tr[posTree[y]].ld) break;
		updateTree(top[y], pos[y], dis);
		dis = tr[top[y]].ld + 1;
	}
}
// query distance: the query city id
int query(int x) {
	int ans = INF;
	// query from x to x's ancestors
	for(int y = x, preDis = 0; y != -1; y = fa[leader[y]]) {
		ans = min(ans, preDis + queryTree(top[y], pos[y]));
		preDis += pos[y]-tr[top[y]].l+1;
	}
	return ans;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	// input edges
	for(int i = 1; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		ed[a].push_back(b);
		ed[b].push_back(a);
	}
	// initialization: build tree
	dfs(1, -1);
	totNode = 0;
	indx = 0;
	build(1, -1);
	insert(1);
	// input queries
	for(int i = 0; i < m; i++) {
		int q, c;
		scanf("%d%d", &q, &c);
		if(q == 1) {
			insert(c);
		} else {
			printf("%d\n", query(c));
		}
	}
	return 0;
}

/*
12 8
1 2
2 4
2 5
5 6
5 7
7 8
1 3
3 12
3 9
9 10
9 11
2 12
2 7
1 6
2 7
1 9
2 10
2 12
2 1

2
3
2
1
2
0


11 9
1 2
2 3
3 4
4 5
4 6
4 7
5 8
6 9
7 10
7 11
2 6
2 9
2 5
2 8
2 7
2 10
2 11
1 5
2 7


4
5
4
5
4
5
5
2
*/