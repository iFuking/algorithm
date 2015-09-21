/*
SAMPLE
3 1 N 3 3
1 1 WL NR *
1 2 WLF NR ER *
1 3 NL ER *
2 1 SL WR NF *
2 2 SL WF ELF *
2 3 SFR EL *
0
NOSOLUTION
3 1 N 3 2
1 1 WL NR *
1 2 NL ER *
2 1 SL WR NFR *
2 2 SR EL *
0
END
*/
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;

// keep every vertex state
typedef struct Node{
	int r;     // row
	int c;     // column
	int dir;   // direction
}Node;
string ignore; // maze's name
int start_r, start_c;
char start_dir;
int end_r, end_c;
const string dirs = "NESW", turns = "FLR";
const int n = 10, direction = 4, turn = 3; 
int d[n][n][direction];   // minumn distance from (start_r, start_c)
Node p[n][n][direction];  // keep parent node of (r, c, dir)
bool has_edge[n][n][direction][turn]; // (row, col) 's signpost
Node st1;
int dir_rc[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
stack<Node> route;

int dir_id(char c) 
{
	if (c == 'N') return 0;
	else if (c == 'E') return 1;
	else if (c == 'S') return 2;
	return 3;
}
//int turn_id(char c) 
//{
//	if (c == 'F') return 0;
//	else if (c == 'L') return 1;
//	return 2;
//}

void init()
{
	cin >> start_r >> start_c >> start_dir;
	cin >> end_r >> end_c;
	int row, col;
	memset(has_edge, 0, sizeof(has_edge));

	// generate has_edge[][][][]
	while (cin >> row && row && cin >> col)
	{
		string dir_turn;  // (row, col) 's signpost
		while (cin >> dir_turn && dir_turn != "*")
		{
			// dir_turn length
			int dir_turn_len = dir_turn.length();
			for (int i = 0; i < direction; i++)
			{
				// has edge only when satisfying direction & turn
				if (dir_turn[0] == dirs[i])		
				{
					int t_num = dir_turn_len-1;
					for (int j = 0; j < t_num; j++)
						for (int k = 0; k < turn; k++)
							if (dir_turn[j+1] == turns[k])
								has_edge[row][col][i][k] = true;
					break;
				}
			}
		}
	}

	// init state (r0, c0) -> (r1, c1, dir1)
	st1.dir = dir_id(start_dir);
	if (start_dir == 'N') { st1.r = start_r-1, st1.c = start_c; }
	else if (start_dir == 'E') { st1.r = start_r, st1.c = start_c+1; }
	else if (start_dir == 'S') { st1.r = start_r+1, st1.c = start_c; }
	else { st1.r = start_r, st1.c = start_c-1; }
	return;
}

bool inside(int row, int col)
{
	if (row>=1 && row<10 && col>=1 && col<10) return true;
	return false;
}

Node walk(Node u, int turn)
{
	int dir = u.dir;
	if (turn == 1) dir = (dir + 3) % 4;  // turn left
	else if (turn == 2) dir = (dir + 1) % 4; // turn right
	Node v = {u.r+dir_rc[dir][0], u.c+dir_rc[dir][1], dir};
	return v;
}

void print_ans(Node u)
{
	Node start = {start_r, start_c, dir_id(start_dir)};
	route.push(u);
	for (Node v = p[u.r][u.c][u.dir]; d[v.r][v.c][v.dir]; v = p[v.r][v.c][v.dir])
		route.push(v);
	route.push(start);

	cout << ignore << endl;
	int cnt = 1; Node v;
	while(!route.empty())
	{
		v = route.top(); route.pop();
		cout << "  " << "(" << v.r << "," << v.c << ")";
		if (cnt % 10 == 0) cout << endl;
		cnt++;
	}
	return;
}

void solve()
{
	queue<Node> q;
	q.push(st1);
	d[st1.r][st1.c][st1.dir] = 0;
	while (!q.empty()) 
	{
		Node u1 = q.front(); q.pop();
		for (int i = 0; i < turn; i++)
		{
			Node u2 = walk(u1, i);
			if (u2.r == end_r && u2.c == end_c) { print_ans(u2); return; }
			if (has_edge[u1.r][u1.c][u1.dir][i] && inside(u2.r,u2.c))
			{
				d[u2.r][u2.c][u2.dir] = d[u1.r][u1.c][u1.dir] + 1;
				p[u2.r][u2.c][u2.dir] = u1;
				q.push(u2);
			}
		}
	}
	cout << "No Solution Possible" << endl;
	return;
}

int main()
{
	while (cin >> ignore && ignore != "END") 
	{
		init();
		solve();
	}
	return 0;
}