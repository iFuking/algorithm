#include <iostream>
#include <queue>
using namespace std;
struct Node{
	int x, y;
}node;

 bool operator<( Node a, Node b){
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}

 int main()
 {
	 return 0;
 }