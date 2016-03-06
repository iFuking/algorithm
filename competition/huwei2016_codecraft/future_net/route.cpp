
#include "route.h"
#include "lib_record.h"
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
using namespace std;


const int maxn = 605;
int net[maxn][maxn];             // future net
int S, T;                        // source, destination
map<int, vector<int> > net_map;  // adjacent list
vector<int> including_set;       // including set


void read_graph(char *graph[5000], map<int, vector<int> > &net_map) {
	for ( ; *graph != NULL; ++graph) {
    	int link_id, s_id, d_id, cost;

    	// scanf from string *graph, split by ','
    	sscanf(*graph, "%d,%d,%d,%d", &link_id, &s_id, &d_id, &cost);

    	// using map to express adjacent list
    	net_map[s_id].push_back(d_id);
    	// 2 demension array records the minimum cost between two nodes
    	net[s_id][d_id] = net[s_id][d_id]>0 ? min(cost,net[s_id][d_id]) : cost;
    }

    // map<int, vector<int> >::iterator iter = net_map.begin();
    // for ( ; iter != net_map.end(); ++iter) {
    // 	printf("%d: ", iter->first);
    // 	vector<int>::iterator it = iter->second.begin();
    // 	for ( ; it != iter->second.end(); ++it) {
    // 		printf("%d,", *it);
    // 	}
    // 	printf("\n");
    // }
	return;
}


void read_condition(char *condition, vector<int> &including_set) {
	// signal count, only two ','s and several '|'s
	// num is the unsigined int value
	int cnt_sig = 0, num = 0;
	for ( ; *condition != '\0'; ++condition) {
		char ch = *condition;
		if (!isdigit(ch)) {
			// the first or the second signal is ','
			if (cnt_sig == 0) S = num;
			else if (cnt_sig == 1) T = num;
			else including_set.push_back(num);

			num = 0;
			++cnt_sig;
		} else num = 10*num+ch-'0';   // tricks to calculate num
	}
	including_set.push_back(num);

	// printf("S: %d\n", S);
	// printf("T: %d\n", T);
	// for (int i = 0; i < including_set.size(); ++i) {
	// 	printf("%d,", including_set[i]);
	// }
	// printf("\n");
	return;
}


void search_route(char *graph[5000], int edge_num, char *condition)
{
    unsigned short result[] = {2, 6, 3};

    for (int i = 0; i < 3; i++)
        record_result(result[i]);
    
    // read string to data structure
    read_graph(graph, net_map);
    read_condition(condition, including_set);
    
    return;
}
