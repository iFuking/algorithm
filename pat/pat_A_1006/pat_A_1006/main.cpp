#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxchar = 20;
typedef struct {
	char id[maxchar];
	int sign_in;
	int sign_out;
}Record;
int M;
vector<Record> record;

bool cmp_in(Record r1, Record r2) { return r1.sign_in < r2.sign_in; }
bool cmp_out(Record r1, Record r2) { return r1.sign_out > r2.sign_out; }

void solve()
{
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		Record r; scanf("%s", r.id);
		int hour, minute, second;
		scanf("%d:%d:%d", &hour, &minute, &second);
		r.sign_in = hour*3600+60*minute+second;
		scanf("%d:%d:%d", &hour, &minute, &second);
		r.sign_out = hour*3600+60*minute+second;
		record.push_back(r);
	}
	sort(record.begin(), record.end(), cmp_in);
	printf("%s ", record[0].id);
	sort(record.begin(), record.end(), cmp_out);
	printf("%s\n", record[0].id);
	return;
}

int main()
{
	solve();
	return 0;
}