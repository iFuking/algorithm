#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
using namespace std;

map<string, vector<string>> title2id;
map<string, vector<string>> author2id;
map<string, vector<string>> keywords2id;
map<string, vector<string>> publisher2id;
map<string, vector<string>> year2id;
const int maxline = 1010;
int N, M;

void init()
{
	cin >> N; getchar();
	for (int i = 0; i < N; ++i)
	{
		char str[maxline];
		string id, title, author, key_words, publisher, year;
		cin.getline(str, maxline); id = str;
		cin.getline(str, maxline); title = str; title2id[title].push_back(id);
		cin.getline(str, maxline); author = str; author2id[author].push_back(id);
		cin.getline(str, maxline); key_words = str;
		istringstream istr(key_words);
		while (!istr.eof()) {
			string keyword; istr >> keyword;
			keywords2id[keyword].push_back(id);
		}
		cin.getline(str, maxline); publisher = str; publisher2id[publisher].push_back(id);
		cin.getline(str, maxline); year = str; year2id[year].push_back(id);
	}
	return;
}

bool cmp(string s1, string s2) { return s1 < s2; }

void solve()
{
	map<string, vector<string>>::iterator it = title2id.begin();
	for ( ; it != title2id.end(); ++it) sort(it->second.begin(), it->second.end(), cmp);
	it = author2id.begin();
	for ( ; it != author2id.end(); ++it) sort(it->second.begin(), it->second.end(), cmp);
	it = keywords2id.begin();
	for ( ; it != keywords2id.end(); ++it) sort(it->second.begin(), it->second.end(), cmp);
	it = publisher2id.end();
	for ( ; it != publisher2id.end(); ++it) sort(it->second.begin(), it->second.end(), cmp);
	it = year2id.end();
	for ( ; it != year2id.end(); ++it) sort(it->second.begin(), it->second.end(), cmp);

	cin >> M; getchar();
	for (int i = 0; i < M; ++i)
	{
		char query[maxline];
		cin.getline(query, maxline);
		string q = query; cout << q << endl;
		q = q.substr(3, q.length());
		if (query[0] == '1') {
			if (title2id[q].size() == 0) { cout << "Not Found" << endl; continue; }
			vector<string>::iterator iter = title2id[q].begin();
			for ( ; iter != title2id[q].end(); ++iter) cout << *iter << endl;
		} else if (query[0] == '2') {
			if (author2id[q].size() == 0) { cout << "Not Found" << endl; continue; }
			vector<string>::iterator iter = author2id[q].begin();
			for ( ; iter != author2id[q].end(); ++iter) cout << *iter << endl;
		} else if (query[0] == '3') {
			if (keywords2id[q].size() == 0) { cout << "Not Found" << endl; continue; }
			vector<string>::iterator iter = keywords2id[q].begin();
			for ( ; iter != keywords2id[q].end(); ++iter) cout << *iter << endl;
		} else if (query[0] == '4') {
			if (publisher2id[q].size() == 0) { cout << "Not Found" << endl; continue; }
			vector<string>::iterator iter = publisher2id[q].begin();
			for ( ; iter != publisher2id[q].end(); ++iter) cout << *iter << endl;
		} else if (query[0] == '5') {
			if (year2id[q].size() == 0) { cout << "Not Found" << endl; continue; }
			vector<string>::iterator iter = year2id[q].begin();
			for ( ; iter != year2id[q].end(); ++iter) cout << *iter << endl;
		} 
	}
	return;
}

int main(int argc, char *argv[])
{
	init();
	solve();
	return 0;
}