#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

struct Node {
    int data;
    ListNode *node;
};


class HashTable {
public:
    HashTable() {
        ht = vector<Node>(hash_size);
    }

    void ht_insert(int x) {
        int idx = x % hash_size;
        ListNode *l = new ListNode(x);
        l->next = ht[idx].node;
        ht[idx].node = l;
        return;
    }

    bool exist(int x) {
        int idx = x % hash_size;
        ListNode *l = ht[idx].node;
        while (l) {
            if (l->val == x) {
                return true;
            }
            l = l->next;
        }
        return false;
    }

    static const int hash_size = 57;
    vector<Node> ht;
};


int main() {
    srand((unsigned int)time(NULL));
    HashTable hash_table;
    for (int i = 0; i < 100; ++i) {
        hash_table.ht_insert(rand()%1000+100);
    }

    for (int i = 0; i < hash_table.hash_size; ++i) {
        ListNode *l = hash_table.ht[i].node;
        cout << i << ": ";
        while (l) {
            cout << l->val << ",";
            l = l->next;
        }
        cout << endl;
    }

    cout << endl;
    cout << endl;
    while (true) {
        int n; cin >> n;
        cout << n << " ";
        if (hash_table.exist(n)) cout << "exists!";
        else cout << "not exists";
        cout << endl;
    }
    return 0;
}
