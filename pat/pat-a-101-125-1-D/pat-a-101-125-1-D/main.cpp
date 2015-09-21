#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <string>
using namespace std;

const int charlen = 10;
typedef struct {
	char plate_number[charlen];
	int time_second;
	bool status;
}Record;

const int maxn = 1e4 + 10;
const int day_seconds = 24*60*60 + 10;
int N, K;
Record record[maxn];

map<string, vector<Record>> plate2record;
vector<Record> records;
int car_total[day_seconds], car_delta[day_seconds];

bool cmp(Record r1, Record r2)
{
	if (r1.time_second != r2.time_second) return r1.time_second < r2.time_second;
	return strcmp(r1.plate_number, r2.plate_number) < 0;
}

bool comp(pair<string, int> p1, pair<string, int> p2)
{
	if (p1.second != p2.second) return p1.second > p2.second;
	return p1.first < p2.first;
}

void solve()
{
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		char plate_number[charlen]; scanf("%s", plate_number);

		int hour, minute, second;
		scanf("%d:%d:%d", &hour, &minute, &second);
		int time_second = second+minute*60+hour*3600;

		char status[charlen]; scanf("%s", status);
		bool state = false;
		if (strcmp(status, "in") == 0) state = true;

		Record re;
		strcpy(re.plate_number, plate_number);
		re.time_second = time_second;
		re.status = state;
		record[i] = re;
	}

	sort(record, record+N, cmp);
	for (int i = 0; i < N; ++i) plate2record[record[i].plate_number].push_back(record[i]);

	map<string, vector<Record>>::iterator iter = plate2record.begin();
	for ( ; iter != plate2record.end(); ++iter)
	{
		vector<Record>::iterator it = iter->second.begin();
		bool expect = true;
		vector<Record> r;
		for ( ; it != iter->second.end(); ++it)
		{
			if (it->status == expect) {
				r.push_back(*it); expect = !expect;
			} else if (it->status!=expect && expect==false) {
				r.pop_back(); r.push_back(*it);
			}
		}
		if (expect == false) r.pop_back();
		plate2record[iter->first] = r;
		for (it = r.begin(); it != r.end(); ++it) records.push_back(*it);
	}

	sort(records.begin(), records.end(), cmp);
	vector<Record>::iterator it = records.begin();
	int cnt = 0;
	for (int i = 0; i < day_seconds; ++i)
	{
		while (it!=records.end() && i==it->time_second) {
			if (it->status == true) ++cnt;
			else --cnt; ++it;
		}
		car_total[i] = cnt;
	}

	for (int i = 0; i < K; ++i)
	{
		int hour, minute, second;
		scanf("%d:%d:%d", &hour, &minute, &second);
		int time_second = second+minute*60+hour*3600;
		printf("%d\n", car_total[time_second]);
	}

	vector<pair<string, int>> time_total;
	iter = plate2record.begin();
	for ( ; iter != plate2record.end(); ++iter)
	{
		int time = 0; vector<Record> r = iter->second;
		for (int i = 0; i < r.size(); i += 2) {
			time += (r[i+1].time_second - r[i].time_second);
		}
		time_total.push_back(make_pair(iter->first, time));
	}
	sort(time_total.begin(), time_total.end(), comp);
	printf("%s ", time_total[0].first.c_str());
	for (int i = 1; i < time_total.size(); ++i) {
		if (time_total[i].second == time_total[0].second) {
			printf("%s ", time_total[i].first.c_str());
		}
	}
	int time_seconds = time_total[0].second;
	int hour = time_seconds / 3600; time_seconds %= 3600;
	int minute = time_seconds / 60; time_seconds %= 60;
	int second = time_seconds;
	printf("%02d:%02d:%02d\n", hour, minute, second);
	return;
}

int main(int argc, char *argv[])
{
	solve();
	return 0;
}


/*
16 7
JH007BD 18:00:01 in
ZD00001 11:30:08 out
DB8888A 13:00:00 out
ZA3Q625 23:59:50 out
ZA133CH 10:23:00 in
ZD00001 04:09:59 in
JH007BD 05:09:59 in
ZA3Q625 11:42:01 out
JH007BD 05:10:33 in
ZA3Q625 06:30:50 in
JH007BD 12:23:42 out
ZA3Q625 23:55:00 in
JH007BD 12:24:23 out
ZA133CH 17:11:22 out
JH007BD 18:07:01 out
DB8888A 06:30:50 in
05:10:00
06:30:50
11:00:00
12:23:42
14:00:00
18:00:00
23:59:00
*/