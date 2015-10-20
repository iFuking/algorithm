#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

const int N = 100005, M = N * 7, inf = 0x7fffffff;
struct Node{
	int v, p;
	bool operator<(const Node & a)const{
		return v>a.v;
	}
	Node(int a, int c) :v(a), p(c){}
};
int n, cnum, pnum;
vector<int>gra[N];
int son[N], fa[N], top[N], siz[N], status[N];
int cp[N], cd[N], csz[N], pn[N], cid[M];
int maxl[M], maxr[M], le[M], ri[M];
priority_queue<Node>que[N];

void dfs_1(int s, int f){
	fa[s] = f; top[s] = s; siz[s] = 1;
	int maxx = 0, p = -1, len = gra[s].size();
	for (int i = 0; i<len; i++){
		int e = gra[s][i]; if (e == f)continue;
		dfs_1(e, s); siz[s] += siz[e];
		if (siz[e]>maxx){ maxx = siz[e]; p = e; }
	}son[s] = p;
}

void update(int p, int rt, int x){ //p偏移量， rt线段树中位置， x重链中位置
	int root = rt + p, lroot = p + (rt << 1), rroot = p + (rt << 1 | 1);
	int l = le[root], r = ri[root], mid = (l + r) >> 1;
	if (l == x && r == x){
		int s = cid[p + x], minn = -1;
		while (!que[s].empty()){
			int v = que[s].top().v;
			int pp = que[s].top().p;
			if (maxl[pp] + 1 != v){
				que[s].pop();
				continue;
			}
			minn = v; 
			break;
		}
		if (status[s]) maxl[root] = maxr[root] = 0;
		else maxl[root] = maxr[root] = minn;
		if (rt == 1 && ~maxl[root]){
			int f = fa[s];
			if (~f) que[f].push(Node(maxl[root] + 1, root));
		}
		return;
	}
	if (x <= mid) update(p, rt << 1, x);
	else update(p, rt << 1 | 1, x);
	maxl[root] = maxr[root] = -1;
	if (~maxl[lroot] && (maxl[root] == -1 || maxl[root]>maxl[lroot]))maxl[root] = maxl[lroot];
	if (~maxl[rroot] && (maxl[root] == -1 || maxl[root]>maxl[rroot] + mid - l + 1))maxl[root] = maxl[rroot] + mid - l + 1;
	if (~maxr[rroot] && (maxr[root] == -1 || maxr[root]>maxr[rroot]))maxr[root] = maxr[rroot];
	if (~maxr[lroot] && (maxr[root] == -1 || maxr[root]>maxr[lroot] + r - mid))maxr[root] = maxr[lroot] + r - mid;
	int s = cid[p + 1];
	if (rt == 1 && ~maxl[root]){
		int f = fa[s];
		if (~f)que[f].push(Node(maxl[root] + 1, root));
	}
}

int queryl(int p, int rt, int l, int r){ //p偏移量， rt线段树中编号， l区间左边界， r区间右边界
	int root = p + rt;
	int mid = (le[root] + ri[root]) >> 1;
	if (l == le[root] && r == ri[root])
		return maxl[root];
	if (r <= mid)return queryl(p, rt << 1, l, r);
	else if (l>mid)return queryl(p, rt << 1 | 1, l, r);
	else{
		int ans = -1;
		int ret = queryl(p, rt << 1, l, mid);
		if (~ret && (ans == -1 || ans>ret))ans = ret;
		ret = queryl(p, rt << 1 | 1, mid + 1, r);
		if (~ret && (ans == -1 || ans>ret + mid - l + 1))ans = ret + mid - l + 1;
		return ans;
	}
}

int queryr(int p, int rt, int l, int r){ //p偏移量， rt线段树中编号， r区间右边界
	int root = p + rt;
	int mid = (le[root] + ri[root]) >> 1;
	if (l == le[root] && r == ri[root])
		return maxr[root];
	if (r <= mid) return queryr(p, rt << 1, l, r);
	else if (l>mid) return queryr(p, rt << 1 | 1, l, r);
	else{
		int ans = -1;
		int ret = queryr(p, rt << 1, l, mid);
		if (~ret && (ans == -1 || ans>ret + r - mid)) ans = ret + r - mid;
		ret = queryr(p, rt << 1 | 1, mid + 1, r);
		if (~ret && (ans == -1 || ans>ret)) ans = ret;
		return ans;
	}
}

void build(int p, int rt, int l, int r){
	int root = rt + p;
	le[root] = l;
	ri[root] = r;
	maxl[root] = maxr[root] = -1;
	int mid = (l + r) >> 1;
	if (l == r)return;
	build(p, rt << 1, l, mid);
	build(p, rt << 1 | 1, mid + 1, r);
}

void dfs_2(int s, int d){
	if (s == top[s]){
		cp[s] = ++cnum; 
		csz[cnum] = 0; 
		pn[cnum] = pnum;
	}
	while (!que[s].empty()) que[s].pop();
	cp[s] = cp[top[s]]; 
	cd[s] = d; 
	int k = cp[s];
	csz[k] = d; 
	cid[d + pn[k]] = s;
	if (~son[s]){
		top[son[s]] = top[s]; 
		dfs_2(son[s], d + 1);
	}
	int len = gra[s].size();
	for (int i = 0; i<len; i++){
		int e = gra[s][i];
		if (e != fa[s] && e != son[s]) dfs_2(e, 1);
	}
	if (son[s] == -1){
		pnum += 6 * d; 
		build(pn[k], 1, 1, d);
	}
}

int main(){
	int n, m, a, b;
	while (scanf("%d%d", &n, &m) != EOF){
		memset(status, 0, sizeof(status));
		for (int i = 0; i < n; i++) gra[i].clear();
		for (int i = 1; i < n; i++){
			scanf("%d%d", &a, &b);
			gra[a].push_back(b);
			gra[b].push_back(a);
		}
		cnum = pnum = 0; 
		dfs_1(1, -1);
		dfs_2(1, 1);
		b = 1;
		status[b] = 1;
		while (~b){
			update(pn[cp[b]], 1, cd[b]);
			b = fa[top[b]];
		}
		while (m--){
			scanf("%d%d", &a, &b);
			if (a == 1){
				status[b] = 1;
				while (~b){
					update(pn[cp[b]], 1, cd[b]);
					b = fa[top[b]];
				}
			}
			else{
				int minn = -1, tmp = 0;
				while (~b){
					int ll = queryl(pn[cp[b]], 1, cd[b], csz[cp[b]]);
					int rr = queryr(pn[cp[b]], 1, 1, cd[b]);
					if (~ll && (minn == -1 || minn>ll + tmp)) minn = ll + tmp;
					if (~rr && (minn == -1 || minn>rr + tmp)) minn = rr + tmp;
					tmp += cd[b]; 
					b = fa[top[b]];
				}
				printf("%d\n", minn);
			}
		}
	}
	return 0;
}