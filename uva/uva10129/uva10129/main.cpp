/*
3
acm
malform
mouse
*/
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef struct Node {
	int vertex;
	Node *next;
}AdjList;
typedef struct Degree {
	int in_degree;
	int out_degree;
}Degree;
const int maxn = 26;
AdjList dir_adj[maxn], undir_adj[maxn];
int T, n;
Degree degree[maxn];
int visit[maxn];

void init()
{
	cin >> n;
	memset(dir_adj, 0, sizeof(dir_adj));
	memset(undir_adj, 0, sizeof(undir_adj));
	for (int i = 0; i < maxn; i++)
	{
		dir_adj[i].vertex = i;
		dir_adj[i].next = NULL;

		undir_adj[i].vertex = i;
		undir_adj[i].next = NULL;
	}

	string word;
	char head, tail;
	memset(degree, 0, sizeof(degree));
	for (int i = 0; i < n; i++)
	{
		cin >> word;
		head = word[0]-'a';
		tail = word[word.length()-1]-'a';

		degree[head].out_degree++;
		degree[tail].in_degree++;

		Node *node = (Node *)malloc(sizeof(Node));
		node->vertex = tail;
		node->next = dir_adj[head].next;
		dir_adj[head].next = node;

		Node *node1 = (Node *)malloc(sizeof(Node));
		node1->vertex = tail;
		node1->next = undir_adj[head].next;
		undir_adj[head].next = node1;
		Node *node2 = (Node *)malloc(sizeof(Node));
		node2->vertex = head;
		node2->next = undir_adj[tail].next;
		undir_adj[tail].next = node2;
	}
	return;
}

void dfs(int vertex)
{
	visit[vertex] = 1;
	Node *node = undir_adj[vertex].next;
	for ( ; node != NULL; node = node->next) 
		if (!visit[node->vertex]) dfs(node->vertex);
	return;
}

bool connected()
{
	memset(visit, 0, sizeof(visit));
	dfs(0);
	int sum = 0;
	for (int i = 0; i < maxn; i++) sum += visit[i];
	if (sum != n) return false;
	return true;
}

bool solve()
{
	if (!connected()) return false;
	int cnt = 0;
	for (int i = 0; i < maxn; i++)
		if (degree[i].in_degree != degree[i].out_degree) cnt++;
	if (cnt > 2) return false;
	return true;
}

int main()
{
	cin >> T;
	while(T--)
	{
		init();
		if (solve()) cout << "Ordering is possible." << endl;
		else cout << "The door cannot be opened." << endl;
	}
	return 0;
}