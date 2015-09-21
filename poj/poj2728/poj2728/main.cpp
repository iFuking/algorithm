#include <iostream>
#include <cmath>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

typedef struct {
	double x, y;
	double h;
}Info;
typedef struct {
	int either, other;
	double weight;
}Edge;
const int maxn = 1010;
const double eps = 1e-4;
int N;
Info v[maxn];
double w[maxn][maxn];
bool mark[maxn];
priority_queue<Edge> pq;

double delta(double x, double y) { return x>y ? x-y : y-x; }
double length(Info v1, Info v2) { return sqrt((v1.x-v2.x)*(v1.x-v2.x)+(v1.y-v2.y)*(v1.y-v2.y)); }
double cost(Info v1, Info v2) { return delta(v1.h, v2.h); }
bool operator <(Edge e1, Edge e2) { return e1.weight > e2.weight; }

void visit(int v)
{
	mark[v] = true;
	for (int i = 0; i < N; i++)
	{
		if (i != v)
		{
			Edge e;
			e.either = v, e.other = i;
			e.weight = w[v][i];
			pq.push(e);
		}
	}
	return;
}

void mst(vector<Edge> &edges)
{
	visit(0);
	while (!pq.empty() && edges.size()<N-1)
	{
		Edge e = pq.top();
		pq.pop();
		int u = e.either, v = e.other;
		if (mark[u] && mark[v]) continue;
		edges.push_back(e);
		if (!mark[u]) visit(u);
		if (!mark[v]) visit(v);
	}
	return;
}

void solve()
{
	while (scanf("%d", &N) && N)
	{
		for (int i = 0; i < N; ++i) scanf("%lf %lf %lf", &v[i].x, &v[i].y, &v[i].h);
		double r = 0.0, r_copy = 1.0;
		while (delta(r, r_copy) > eps)
		{
			r_copy = r;
			pq = priority_queue<Edge>();
			memset(mark, 0, sizeof(mark));
			vector<Edge> edges;
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					w[i][j] = cost(v[i],v[j])-r*length(v[i],v[j]);
				}
			}
			mst(edges);
			double cst = 0.0, lng = 0.0;
			for (int i = 0; i < edges.size(); ++i) {
				cst += cost(v[edges[i].either], v[edges[i].other]);
				lng += length(v[edges[i].either], v[edges[i].other]);
			}
			r = cst/lng;
		}
		printf("%.3f\n", r);
	}
	return;
}

int main()
{
	solve();
	return 0;
}


/*
4
0 0 0
0 1 1
1 1 2
1 0 3
*/